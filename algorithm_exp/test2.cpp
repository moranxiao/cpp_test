#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ifstream in("input.txt");
    if (!in.is_open()) exit(1);

    int k;
    string num;
    in >> num >> k;
    stack<char> st;

    for (int i = 0; i < num.size(); i++) {
        while (k > 0 && !st.empty() && st.top() > num[i]) {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }

    // �����Ҫɾ��ʣ���k������
    while (k > 0) {
        st.pop();
        k--;
    }

    // �������ַ���
    string res;
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }

    // ����ǰ��0��������Ϊ�գ����� "0"
    int start = 0;
    while (start < res.size() && res[start] == '0') {
        start++;
    }

    res = res.substr(start);

    // ���ɾ���������ֻ��߽��Ϊ�գ��򷵻� "0"
    if (res.empty()) {
        res = "0";
    }

    ofstream out("output.txt");
    if (!out.is_open()) exit(2);
    out << res;

    in.close();
    out.close();
    return 0;
}
