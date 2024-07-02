#include<Windows.h>
#include <sql.h>
#include <sqlext.h> 
#include <sqltypes.h>
#include <iostream>
#include <string>

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
void connect()//���ݿ����Ӻ���
{
    SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv);//���뻷��
    SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);//���û���
    SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);//�������ݿ�����
    //��������
    ret = SQLConnect(hdbc, (SQLTCHAR*)("exp4"), SQL_NTS, (SQLTCHAR*)("sa"), SQL_NTS, (SQLTCHAR*)("27182818"), SQL_NTS);
    if ((ret == SQL_SUCCESS) || (ret == SQL_SUCCESS_WITH_INFO))
    {
        cout << "���ݿ����ӳɹ�!" << endl;
    }
    else
    {
        cout << "���ݿ�����ʧ�ܣ�" << endl;
    }
}
//�ͷſռ�
void free()
{
    SQLFreeHandle(SQL_HANDLE_STMT, hstmt);//�ͷ����
    SQLFreeHandle(SQL_HANDLE_DBC, hdbc);//�ͷ�����
    SQLFreeHandle(SQL_HANDLE_ENV, henv);//�ͷŻ���
}
void exec()
{
    //���������
    ret = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
    // ׼��SQL���ô洢���̵����  
    const char* callProc = "exec DiscreteMath_count @cname=?"; // ? Ϊռλ�������ڽ������Ĳ�����
    ret = SQLPrepare(hstmt, (SQLCHAR*)callProc, SQL_NTS); //���sql
    string cname = "��ɢ��ѧ";  
    //������
    ret = SQLBindParameter(hstmt, 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 50, 0, (SQLPOINTER)cname.c_str(), cname.size()-1, NULL);
    //ִ��sql
    ret = SQLExecute(hstmt);
    //�������
    cout << "begin\t" << "end\t" << "grade\t" << endl;
    // �����һ�������
    if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
    {
        do {
            SQLCHAR buffer[3][10];
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
}
int main() 
{
    connect();
    //ִ�д洢���̣���ͳ����ɢ��ѧ�����ֶε�����
    exec();
    free();
    return 0;
}
