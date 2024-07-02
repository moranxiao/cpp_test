#include<Windows.h>
#include <iostream>
#include <string>
#include <sqltypes.h>
#include <sqlext.h> 

#undef SQLConnect
//����<sqlext.h>�ж�SQLConnect�����˺궨�壬��sql.h�е�SQLConnect��ͻ�ˣ��ᵼ�µ��ò����˺��� 
#undef SQLPrepare
#undef SQLGetDiagRec


using namespace std;
SQLRETURN ret = NULL;//������Ϣ
SQLHENV henv = NULL;//�������
SQLHDBC hdbc = NULL;//���Ӿ��
SQLHSTMT hstmt = NULL;//�����


void PrintODBCError(SQLSMALLINT HandleType, SQLHANDLE Handle) {
    SQLSMALLINT i = 1;
    SQLINTEGER  NativeError;
    SQLSTATE    Sqlstate[5];
    SQLCHAR     MessageText[SQL_MAX_MESSAGE_LENGTH + 1];
    SQLSMALLINT TextLength;
    SQLSMALLINT BufferLength = SQL_MAX_MESSAGE_LENGTH + 1;

    while (SQLGetDiagRec(HandleType, Handle, i, (SQLCHAR*)Sqlstate, &NativeError, MessageText, BufferLength, &TextLength) == SQL_SUCCESS) {
        MessageText[TextLength] = '\0'; // ȷ���ַ�����null��β  
        std::cerr << "SQL Error: " << (char*)MessageText << " (" << (int)Sqlstate[0] << ")" << std::endl;
        i++;
    }
}
void Connect()//���ݿ����Ӻ���
{
    SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);//���뻷��
    SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);//���û���
    SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);//�������ݿ�����
    //��������
    ret = SQLConnect(hdbc, (SQLCHAR*)("exp4"), SQL_NTS, (SQLCHAR*)("sa"), SQL_NTS, (SQLCHAR*)("27182818"), SQL_NTS);

    if ((ret != SQL_SUCCESS) && (ret != SQL_SUCCESS_WITH_INFO))
    {
        PrintODBCError(SQL_HANDLE_STMT, hstmt);
    }

}

//�ͷſռ�
void FreeSql()
{
    SQLFreeHandle(SQL_HANDLE_STMT, hstmt);//�ͷ����
    SQLFreeHandle(SQL_HANDLE_DBC, hdbc);//�ͷ�����
    SQLFreeHandle(SQL_HANDLE_ENV, henv);//�ͷŻ���
}
void print()
{
    cout << "*********************************************************" << endl;
    cout << "*****  1.��ѯѧ����Ϣ     2.����ѧ��           **********" << endl;
    cout << "*****  3.��ѯ�γ���Ϣ     4.ѧ��ѡ��           **********" << endl;
    cout << "*****  5.��ѯѡ����Ϣ     6.ɾ��ѧ��           **********" << endl;
    cout << "*****  7.��ѯ��־��Ϣ     8.�γ̳ɼ���Ϣ       **********" << endl;
    cout << "*************************************************" << endl;

}

void SelectStu()
{
    Connect();
    //���������
    ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    ret = SQLPrepare(hstmt, (SQLCHAR*)"select * from Student", SQL_NTS); //���sql
    ret = SQLExecute(hstmt);
    
    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
    {
        do {
            SQLCHAR buffer[4][20];
            // �����������ÿһ��  
            while (SQLFetch(hstmt) == SQL_SUCCESS) {
                ret = SQLGetData(hstmt, 1, SQL_C_CHAR, buffer[0], sizeof(buffer[0]), nullptr);
                ret = SQLGetData(hstmt, 2, SQL_C_CHAR, buffer[1], sizeof(buffer[1]), nullptr);
                ret = SQLGetData(hstmt, 3, SQL_C_CHAR, buffer[2], sizeof(buffer[2]), nullptr);
                ret = SQLGetData(hstmt, 4, SQL_C_CHAR, buffer[3], sizeof(buffer[3]), nullptr);

                cout << buffer[0] << '\t' << buffer[1] << '\t' << buffer[2] << '\t' << buffer[3] << endl;
            }
            // ����Ƿ��и���Ľ����  
            ret = SQLMoreResults(hstmt);
        } while (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO);
    }
    else
    {
        //���������Ϣ
        PrintODBCError(SQL_HANDLE_STMT, hstmt);
    }
    FreeSql();
}
void SelectCourse()
{
    Connect();
    //���������
    ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    ret = SQLPrepare(hstmt, (SQLCHAR*)"select * from Course", SQL_NTS); //���sql
    ret = SQLExecute(hstmt);
    printf("c_id\tc_name\tc_credit\n");
    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
    {
        do {
            SQLCHAR buffer[4][20];
            // �����������ÿһ��  
            while (SQLFetch(hstmt) == SQL_SUCCESS) {
                ret = SQLGetData(hstmt, 1, SQL_C_CHAR, buffer[0], sizeof(buffer[0]), nullptr);
                ret = SQLGetData(hstmt, 2, SQL_C_CHAR, buffer[1], sizeof(buffer[1]), nullptr);
                ret = SQLGetData(hstmt, 3, SQL_C_CHAR, buffer[2], sizeof(buffer[2]), nullptr);

                cout << buffer[0] << '\t' << buffer[1] << '\t' << buffer[2] << endl;
            }
            // ����Ƿ��и���Ľ����  
            ret = SQLMoreResults(hstmt);
        } while (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO);
    }
    else
    {
        //���������Ϣ
        PrintODBCError(SQL_HANDLE_STMT, hstmt);
    }
    FreeSql();
}

void SelectScore()
{
    Connect();
    //���������
    ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    ret = SQLPrepare(hstmt, (SQLCHAR*)"select * from Score", SQL_NTS); //���sql
    ret = SQLExecute(hstmt);
    printf("s_id\tc_id\tgrade\n");
    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
    {
        do {
            SQLCHAR buffer[4][20];
            // �����������ÿһ��  
            while (SQLFetch(hstmt) == SQL_SUCCESS) {
                ret = SQLGetData(hstmt, 1, SQL_C_CHAR, buffer[0], sizeof(buffer[0]), nullptr);
                ret = SQLGetData(hstmt, 2, SQL_C_CHAR, buffer[1], sizeof(buffer[1]), nullptr);
                ret = SQLGetData(hstmt, 3, SQL_C_CHAR, buffer[2], sizeof(buffer[2]), nullptr);

                cout << buffer[0] << '\t' << buffer[1] << '\t' << buffer[2] << endl;
            }
            // ����Ƿ��и���Ľ����  
            ret = SQLMoreResults(hstmt);
        } while (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO);
    }
    else
    {
        //���������Ϣ
        PrintODBCError(SQL_HANDLE_STMT, hstmt);
    }
    FreeSql();
}

void PrintLog()
{
    Connect();
    //���������
    ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    ret = SQLPrepare(hstmt, (SQLCHAR*)"select * from UpdateLog", SQL_NTS); //���sql

    ret = SQLExecute(hstmt);
    printf("log_id\ttable_name\toption\told_data\tnew_data\n");
    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
    {
        do {
            SQLCHAR buffer[5][1024];
            SQLLEN indicator[5];
            // �����������ÿһ��  
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
            // ����Ƿ��и���Ľ����  
            ret = SQLMoreResults(hstmt);
        } while (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO);
    }
    else
    {
        //���������Ϣ
        PrintODBCError(SQL_HANDLE_STMT, hstmt);
    }
    FreeSql();
}
void InsertStu()
{
    Connect();
    //���������
    ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    ret = SQLPrepare(hstmt, (SQLCHAR*)"insert Student values(?,?,?,?)", SQL_NTS); //���sql

    string s_id, s_name, s_major, s_inyear;
    cout <<"������s_id,s_name, s_major, s_inyear,�Կո�ָ�>:";
    cin >> s_id >> s_name >> s_major >> s_inyear;
    //������
    ret = SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, (SQLPOINTER)s_id.c_str(), s_id.size() - 1, NULL);
    ret = SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, (SQLPOINTER)s_name.c_str(), s_name.size() - 1, NULL);
    ret = SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, (SQLPOINTER)s_major.c_str(), s_name.size() - 1, NULL);
    ret = SQLBindParameter(hstmt, 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, (SQLPOINTER)s_inyear.c_str(), s_inyear.size() - 1, NULL);

    ret = SQLExecute(hstmt);

    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
    {
        cout << "����ɹ�" << endl;
    }
    else
    {
        //���������Ϣ
        PrintODBCError(SQL_HANDLE_STMT, hstmt);
    }
    FreeSql();
}

void DeleteStu()
{
    Connect();
    //���������
    ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    ret = SQLPrepare(hstmt, (SQLCHAR*)"delete Student where s_id=?", SQL_NTS); //���sql

    string s_id;
    cout << "������s_id >:";
    cin >> s_id;
    //������
    ret = SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, (SQLPOINTER)s_id.c_str(), s_id.size() - 1, NULL);

    ret = SQLExecute(hstmt);

    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
    {
        cout << "ɾ���ɹ�" << endl;
    }
    else
    {
        //���������Ϣ
        PrintODBCError(SQL_HANDLE_STMT, hstmt);
    }
    FreeSql();
}
void CourseGradeInfo()
{
    Connect();

    //���������
    ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    // ׼��SQL���ô洢���̵����  
    const char* callProc = "exec GradeInfo @c_id=?"; // ? Ϊռλ�������ڽ������Ĳ�����
    ret = SQLPrepare(hstmt, (SQLCHAR*)callProc, SQL_NTS); //���sql
    string c_id;
    cout << "������c_id >:";
    cin >> c_id;
    //������
    ret = SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, (SQLPOINTER)c_id.c_str(), c_id.size() - 1, NULL);
    //ִ��sql
    ret = SQLExecute(hstmt);
    //�������
    printf("avg\tmax\tmin\t0-59\t60-69\t70-79\t80-89\t90-100\n");
    // �����һ�������
    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
    {
        do {
            SQLCHAR buffer[8][20];
            SQLLEN indicator[8];
            // �����������ÿһ��  
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
            // ����Ƿ��и���Ľ����  
            ret = SQLMoreResults(hstmt);
        } while (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO);
    }
    else
    {
        //���������Ϣ
        PrintODBCError(SQL_HANDLE_STMT, hstmt);
    }
    FreeSql();

}

void InsertScore()
{
    Connect();
    //���������
    ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    // ׼��SQL���ô洢���̵����  
    const char* callProc = "insert Score values(?,?,?)"; // ? Ϊռλ�������ڽ������Ĳ�����
    
    ret = SQLPrepare(hstmt, (SQLCHAR*)callProc, SQL_NTS); //���sql
    
    string s_id, c_id, grade;
    cout << "������s_id, c_id, grade���ո�ָ� >:";
    cin >> s_id >> c_id >> grade;
    //������
    ret = SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, (SQLPOINTER)s_id.c_str(), s_id.size() - 1, NULL);
    ret = SQLBindParameter(hstmt, 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, (SQLPOINTER)c_id.c_str(), c_id.size() - 1, NULL);
    ret = SQLBindParameter(hstmt, 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, (SQLPOINTER)grade.c_str(), grade.size() - 1,NULL);

    //ִ��sql
    
    ret = SQLExecute(hstmt);
    
    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
    {
        cout << "��ӳɹ���" << endl;
    }
    else
    {
        //���������Ϣ
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
        cout << "������ѡ��>:";
        cin >> opt;
        switch (opt)
        {
        case 0:
            break;
        case 1://��ѯѧ����Ϣ
            SelectStu();
            break;
        case 2://����ѧ��
            InsertStu();
            break;
        case 3://��ѯ�γ���Ϣ
            SelectCourse();
            break;
        case 4://ѧ��ѡ��
            InsertScore();
            break;
        case 5://��ѯѡ����Ϣ
            SelectScore();
            break;
        case 6://ɾ��ѧ��
            DeleteStu();
            break;
        case 7://��ӡ��־��Ϣ
            PrintLog();
            break;
        case 8://ͳ�ƿγ̳ɼ���Ϣ
            CourseGradeInfo();
            break;
        default:
            cout << "�����������������룡" << endl;
            break;
        }
    } while(opt);
    return 0;
}