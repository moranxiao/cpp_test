#include<Windows.h>
#include <sql.h>
#include <sqlext.h> 
#include <sqltypes.h>
#include <iostream>
#include <string>

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
void connect()//数据库连接函数
{
    SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);//申请环境
    SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);//设置环境
    SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);//申请数据库连接
    //建立连接
    ret = SQLConnect(hdbc, (SQLTCHAR*)("exp4"), SQL_NTS, (SQLTCHAR*)("sa"), SQL_NTS, (SQLTCHAR*)("27182818"), SQL_NTS);
    if ((ret == SQL_SUCCESS) || (ret == SQL_SUCCESS_WITH_INFO))
    {
        cout << "数据库连接成功!" << endl;
    }
    else
    {
        cout << "数据库连接失败！" << endl;
    }
}
//释放空间
void free()
{
    SQLFreeHandle(SQL_HANDLE_STMT, hstmt);//释放语句
    SQLFreeHandle(SQL_HANDLE_DBC, hdbc);//释放连接
    SQLFreeHandle(SQL_HANDLE_ENV, henv);//释放环境
}
void exec()
{
    //申请语句句柄
    ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    // 准备SQL调用存储过程的语句  
    const char* callProc = "exec DiscreteMath_count @cname=?"; // ? 为占位符，用于接下来的参数绑定
    ret = SQLPrepare(hstmt, (SQLCHAR*)callProc, SQL_NTS); //添加sql
    string cname = "离散数学";  
    //参数绑定
    ret = SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, (SQLPOINTER)cname.c_str(), cname.size()-1, NULL);
    //执行sql
    ret = SQLExecute(hstmt);
    //输出列名
    cout << "begin\t" << "end\t" << "grade\t" << endl;
    // 处理第一个结果集
    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
    {
        do {
            SQLCHAR buffer[3][10];
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
}
int main() 
{
    connect();
    //执行存储过程，即统计离散数学各个分段的人数
    exec();
    free();
    return 0;
}
