#include<Windows.h>
#include <iostream>
#include <string>
#include <sqltypes.h>
#include <sqlext.h> 

#undef SQLConnect
//由于<sqlext.h>中对SQLConnect进行了宏定义，和sql.h中的SQLConnect冲突了，会导致调用不到此函数 
#undef SQLPrepare
#undef SQLGetDiagRec


using namespace std;
SQLRETURN ret = NULL;//返回信息
SQLHENV henv = NULL;//环境句柄
SQLHDBC hdbc = NULL;//连接句柄
SQLHSTMT hstmt = NULL;//语句句柄


void PrintODBCError(SQLSMALLINT HandleType, SQLHANDLE Handle) {
    SQLSMALLINT i = 1;
    SQLINTEGER  NativeError;
    SQLSTATE    Sqlstate[5];
    SQLCHAR     MessageText[SQL_MAX_MESSAGE_LENGTH + 1];
    SQLSMALLINT TextLength;
    SQLSMALLINT BufferLength = SQL_MAX_MESSAGE_LENGTH + 1;

    while (SQLGetDiagRec(HandleType, Handle, i, (SQLCHAR*)Sqlstate, &NativeError, MessageText, BufferLength, &TextLength) == SQL_SUCCESS) {
        MessageText[TextLength] = '\0'; // 确保字符串以null结尾  
        std::cerr << "SQL Error: " << (char*)MessageText << " (" << (int)Sqlstate[0] << ")" << std::endl;
        i++;
    }
}
void Connect()//数据库连接函数
{
    SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);//申请环境
    SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);//设置环境
    SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);//申请数据库连接
    //建立连接
    ret = SQLConnect(hdbc, (SQLCHAR*)("exp4"), SQL_NTS, (SQLCHAR*)("sa"), SQL_NTS, (SQLCHAR*)("27182818"), SQL_NTS);

    if ((ret != SQL_SUCCESS) && (ret != SQL_SUCCESS_WITH_INFO))
    {
        PrintODBCError(SQL_HANDLE_STMT, hstmt);
    }

}

//释放空间
void FreeSql()
{
    SQLFreeHandle(SQL_HANDLE_STMT, hstmt);//释放语句
    SQLFreeHandle(SQL_HANDLE_DBC, hdbc);//释放连接
    SQLFreeHandle(SQL_HANDLE_ENV, henv);//释放环境
}
void print()
{
    cout << "*********************************************************" << endl;
    cout << "*****  1.查询学生信息     2.插入学生           **********" << endl;
    cout << "*****  3.查询课程信息     4.学生选课           **********" << endl;
    cout << "*****  5.查询选课信息     6.删除学生           **********" << endl;
    cout << "*****  7.查询日志信息     8.课程成绩信息       **********" << endl;
    cout << "*************************************************" << endl;

}

void SelectStu()
{
    Connect();
    //申请语句句柄
    ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    ret = SQLPrepare(hstmt, (SQLCHAR*)"select * from Student", SQL_NTS); //添加sql
    ret = SQLExecute(hstmt);
    
    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
    {
        do {
            SQLCHAR buffer[4][20];
            // 遍历结果集的每一行  
            while (SQLFetch(hstmt) == SQL_SUCCESS) {
                ret = SQLGetData(hstmt, 1, SQL_C_CHAR, buffer[0], sizeof(buffer[0]), nullptr);
                ret = SQLGetData(hstmt, 2, SQL_C_CHAR, buffer[1], sizeof(buffer[1]), nullptr);
                ret = SQLGetData(hstmt, 3, SQL_C_CHAR, buffer[2], sizeof(buffer[2]), nullptr);
                ret = SQLGetData(hstmt, 4, SQL_C_CHAR, buffer[3], sizeof(buffer[3]), nullptr);

                cout << buffer[0] << '\t' << buffer[1] << '\t' << buffer[2] << '\t' << buffer[3] << endl;
            }
            // 检查是否还有更多的结果集  
            ret = SQLMoreResults(hstmt);
        } while (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO);
    }
    else
    {
        //输出错误信息
        PrintODBCError(SQL_HANDLE_STMT, hstmt);
    }
    FreeSql();
}
void SelectCourse()
{
    Connect();
    //申请语句句柄
    ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    ret = SQLPrepare(hstmt, (SQLCHAR*)"select * from Course", SQL_NTS); //添加sql
    ret = SQLExecute(hstmt);
    printf("c_id\tc_name\tc_credit\n");
    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
    {
        do {
            SQLCHAR buffer[4][20];
            // 遍历结果集的每一行  
            while (SQLFetch(hstmt) == SQL_SUCCESS) {
                ret = SQLGetData(hstmt, 1, SQL_C_CHAR, buffer[0], sizeof(buffer[0]), nullptr);
                ret = SQLGetData(hstmt, 2, SQL_C_CHAR, buffer[1], sizeof(buffer[1]), nullptr);
                ret = SQLGetData(hstmt, 3, SQL_C_CHAR, buffer[2], sizeof(buffer[2]), nullptr);

                cout << buffer[0] << '\t' << buffer[1] << '\t' << buffer[2] << endl;
            }
            // 检查是否还有更多的结果集  
            ret = SQLMoreResults(hstmt);
        } while (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO);
    }
    else
    {
        //输出错误信息
        PrintODBCError(SQL_HANDLE_STMT, hstmt);
    }
    FreeSql();
}

void SelectScore()
{
    Connect();
    //申请语句句柄
    ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    ret = SQLPrepare(hstmt, (SQLCHAR*)"select * from Score", SQL_NTS); //添加sql
    ret = SQLExecute(hstmt);
    printf("s_id\tc_id\tgrade\n");
    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
    {
        do {
            SQLCHAR buffer[4][20];
            // 遍历结果集的每一行  
            while (SQLFetch(hstmt) == SQL_SUCCESS) {
                ret = SQLGetData(hstmt, 1, SQL_C_CHAR, buffer[0], sizeof(buffer[0]), nullptr);
                ret = SQLGetData(hstmt, 2, SQL_C_CHAR, buffer[1], sizeof(buffer[1]), nullptr);
                ret = SQLGetData(hstmt, 3, SQL_C_CHAR, buffer[2], sizeof(buffer[2]), nullptr);

                cout << buffer[0] << '\t' << buffer[1] << '\t' << buffer[2] << endl;
            }
            // 检查是否还有更多的结果集  
            ret = SQLMoreResults(hstmt);
        } while (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO);
    }
    else
    {
        //输出错误信息
        PrintODBCError(SQL_HANDLE_STMT, hstmt);
    }
    FreeSql();
}

void PrintLog()
{
    Connect();
    //申请语句句柄
    ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    ret = SQLPrepare(hstmt, (SQLCHAR*)"select * from UpdateLog", SQL_NTS); //添加sql

    ret = SQLExecute(hstmt);
    printf("log_id\ttable_name\toption\told_data\tnew_data\n");
    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
    {
        do {
            SQLCHAR buffer[5][1024];
            SQLLEN indicator[5];
            // 遍历结果集的每一行  
            while (SQLFetch(hstmt) == SQL_SUCCESS) {
                ret = SQLGetData(hstmt, 1, SQL_C_CHAR, buffer[0], sizeof(buffer[0]), &indicator[0]);
                if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
                    if (indicator[0] == SQL_NULL_DATA) {
                        std::cout << "NULL\t";
                    }
                    else {
                        std::cout << buffer[0] << "\t";
                    }
                }

                ret = SQLGetData(hstmt, 2, SQL_C_CHAR, buffer[1], sizeof(buffer[1]), &indicator[1]);
                if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
                    if (indicator[1] == SQL_NULL_DATA) {
                        std::cout << "NULL\t";
                    }
                    else {
                        std::cout << buffer[1] << "\t";
                    }
                }

                ret = SQLGetData(hstmt, 3, SQL_C_CHAR, buffer[2], sizeof(buffer[2]), &indicator[2]);
                if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
                    if (indicator[2] == SQL_NULL_DATA) {
                        std::cout << "NULL\t";
                    }
                    else {
                        std::cout << buffer[2] << "\t";
                    }
                }

                ret = SQLGetData(hstmt, 4, SQL_C_CHAR, buffer[3], sizeof(buffer[3]), &indicator[3]);
                if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
                    if (indicator[3] == SQL_NULL_DATA) {
                        std::cout << "NULL\t";
                    }
                    else {
                        std::cout << buffer[3] << "\t";
                    }
                }

                ret = SQLGetData(hstmt, 5, SQL_C_CHAR, buffer[4], sizeof(buffer[4]), &indicator[4]);
                if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
                    if (indicator[4] == SQL_NULL_DATA) {
                        std::cout << "NULL";
                    }
                    else {
                        std::cout << buffer[4];
                    }
                }
                cout << endl;

            }
            // 检查是否还有更多的结果集  
            ret = SQLMoreResults(hstmt);
        } while (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO);
    }
    else
    {
        //输出错误信息
        PrintODBCError(SQL_HANDLE_STMT, hstmt);
    }
    FreeSql();
}
void InsertStu()
{
    Connect();
    //申请语句句柄
    ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    ret = SQLPrepare(hstmt, (SQLCHAR*)"insert Student values(?,?,?,?)", SQL_NTS); //添加sql

    string s_id, s_name, s_major, s_inyear;
    cout <<"请输入s_id,s_name, s_major, s_inyear,以空格分割>:";
    cin >> s_id >> s_name >> s_major >> s_inyear;
    //参数绑定
    ret = SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, (SQLPOINTER)s_id.c_str(), s_id.size() - 1, NULL);
    ret = SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, (SQLPOINTER)s_name.c_str(), s_name.size() - 1, NULL);
    ret = SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, (SQLPOINTER)s_major.c_str(), s_name.size() - 1, NULL);
    ret = SQLBindParameter(hstmt, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, (SQLPOINTER)s_inyear.c_str(), s_inyear.size() - 1, NULL);

    ret = SQLExecute(hstmt);

    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
    {
        cout << "插入成功" << endl;
    }
    else
    {
        //输出错误信息
        PrintODBCError(SQL_HANDLE_STMT, hstmt);
    }
    FreeSql();
}

void DeleteStu()
{
    Connect();
    //申请语句句柄
    ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    ret = SQLPrepare(hstmt, (SQLCHAR*)"delete Student where s_id=?", SQL_NTS); //添加sql

    string s_id;
    cout << "请输入s_id >:";
    cin >> s_id;
    //参数绑定
    ret = SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, (SQLPOINTER)s_id.c_str(), s_id.size() - 1, NULL);

    ret = SQLExecute(hstmt);

    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
    {
        cout << "删除成功" << endl;
    }
    else
    {
        //输出错误信息
        PrintODBCError(SQL_HANDLE_STMT, hstmt);
    }
    FreeSql();
}
void CourseGradeInfo()
{
    Connect();

    //申请语句句柄
    ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    // 准备SQL调用存储过程的语句  
    const char* callProc = "exec GradeInfo @c_id=?"; // ? 为占位符，用于接下来的参数绑定
    ret = SQLPrepare(hstmt, (SQLCHAR*)callProc, SQL_NTS); //添加sql
    string c_id;
    cout << "请输入c_id >:";
    cin >> c_id;
    //参数绑定
    ret = SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, (SQLPOINTER)c_id.c_str(), c_id.size() - 1, NULL);
    //执行sql
    ret = SQLExecute(hstmt);
    //输出列名
    printf("avg\tmax\tmin\t0-59\t60-69\t70-79\t80-89\t90-100\n");
    // 处理第一个结果集
    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
    {
        do {
            SQLCHAR buffer[8][20];
            SQLLEN indicator[8];
            // 遍历结果集的每一行  
            while (SQLFetch(hstmt) == SQL_SUCCESS) {
                ret = SQLGetData(hstmt, 1, SQL_C_CHAR, buffer[0], sizeof(buffer[0]), &indicator[0]);
                if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
                    if (indicator[0] == SQL_NULL_DATA) {
                        std::cout << "NULL\t";
                    }
                    else {
                        std::cout << buffer[0] << "\t";
                    }
                }

                ret = SQLGetData(hstmt, 2, SQL_C_CHAR, buffer[1], sizeof(buffer[1]), &indicator[1]);
                if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
                    if (indicator[1] == SQL_NULL_DATA) {
                        std::cout << "NULL\t";
                    }
                    else {
                        std::cout << buffer[1] << "\t";
                    }
                }

                ret = SQLGetData(hstmt, 3, SQL_C_CHAR, buffer[2], sizeof(buffer[2]), &indicator[2]);
                if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
                    if (indicator[2] == SQL_NULL_DATA) {
                        std::cout << "NULL\t";
                    }
                    else {
                        std::cout << buffer[2] << "\t";
                    }
                }

                ret = SQLGetData(hstmt, 4, SQL_C_CHAR, buffer[3], sizeof(buffer[3]), &indicator[3]);
                if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
                    if (indicator[3] == SQL_NULL_DATA) {
                        std::cout << "NULL\t";
                    }
                    else {
                        std::cout << buffer[3] << "\t";
                    }
                }

                ret = SQLGetData(hstmt, 5, SQL_C_CHAR, buffer[4], sizeof(buffer[4]), &indicator[4]);
                if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
                    if (indicator[4] == SQL_NULL_DATA) {
                        std::cout << "NULL\t";
                    }
                    else {
                        std::cout << buffer[4] << "\t";
                    }
                }
                ret = SQLGetData(hstmt, 6, SQL_C_CHAR, buffer[5], sizeof(buffer[5]), &indicator[5]);
                if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
                    if (indicator[5] == SQL_NULL_DATA) {
                        std::cout << "NULL\t";
                    }
                    else {
                        std::cout << buffer[5] << "\t";
                    }
                }
                ret = SQLGetData(hstmt, 7, SQL_C_CHAR, buffer[6], sizeof(buffer[6]), &indicator[6]);
                if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
                    if (indicator[6] == SQL_NULL_DATA) {
                        std::cout << "NULL\t";
                    }
                    else {
                        std::cout << buffer[6] << "\t";
                    }
                }
                ret = SQLGetData(hstmt, 8, SQL_C_CHAR, buffer[7], sizeof(buffer[7]), &indicator[7]);
                if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO) {
                    if (indicator[7] == SQL_NULL_DATA) {
                        std::cout << "NULL";
                    }
                    else {
                        std::cout << buffer[7];
                    }
                }
                cout << endl;

            }
            // 检查是否还有更多的结果集  
            ret = SQLMoreResults(hstmt);
        } while (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO);
    }
    else
    {
        //输出错误信息
        PrintODBCError(SQL_HANDLE_STMT, hstmt);
    }
    FreeSql();

}

void InsertScore()
{
    Connect();
    //申请语句句柄
    ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    // 准备SQL调用存储过程的语句  
    const char* callProc = "insert Score values(?,?,?)"; // ? 为占位符，用于接下来的参数绑定
    
    ret = SQLPrepare(hstmt, (SQLCHAR*)callProc, SQL_NTS); //添加sql
    
    string s_id, c_id, grade;
    cout << "请输入s_id, c_id, grade，空格分割 >:";
    cin >> s_id >> c_id >> grade;
    //参数绑定
    ret = SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, (SQLPOINTER)s_id.c_str(), s_id.size() - 1, NULL);
    ret = SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, (SQLPOINTER)c_id.c_str(), c_id.size() - 1, NULL);
    ret = SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, (SQLPOINTER)grade.c_str(), grade.size() - 1,NULL);

    //执行sql
    
    ret = SQLExecute(hstmt);
    
    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
    {
        cout << "添加成功！" << endl;
    }
    else
    {
        //输出错误信息
        PrintODBCError(SQL_HANDLE_STMT, hstmt);
    }
    FreeSql();
}
int main()
{
    int opt;
    do
    {
        print();
        cout << "请输入选项>:";
        cin >> opt;
        switch (opt)
        {
        case 0:
            break;
        case 1://查询学生信息
            SelectStu();
            break;
        case 2://插入学生
            InsertStu();
            break;
        case 3://查询课程信息
            SelectCourse();
            break;
        case 4://学生选课
            InsertScore();
            break;
        case 5://查询选课信息
            SelectScore();
            break;
        case 6://删除学生
            DeleteStu();
            break;
        case 7://打印日志信息
            PrintLog();
            break;
        case 8://统计课程成绩信息
            CourseGradeInfo();
            break;
        default:
            cout << "输入有误，请重新输入！" << endl;
            break;
        }
    } while(opt);
    return 0;
}