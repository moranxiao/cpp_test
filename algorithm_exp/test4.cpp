#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string q;
int n;

void backtrack(vector<string>& res, string& cur, vector<bool>& used) {
    if (cur.size() == q.size()) {
        res.push_back(cur);  // ���һ������
        return;
    }

    for (int i = 0; i < q.size(); i++) 
    {
        if (used[i]) continue;  // ����Ѿ�ʹ�ù���Ԫ�أ�����

        // ��ֹ�ظ�����
        if (i > 0 && q[i] == q[i - 1] && !used[i - 1]) continue;

        used[i] = true;
        cur.push_back(q[i]);
        backtrack(res, cur, used);
        used[i] = false;
        cur.pop_back();
    }
}

int main() {
    ifstream in("input.txt");
    if (!in.is_open()) exit(1);

    in >> n >> q;
    sort(q.begin(), q.end());  // �����ַ���

    vector<string> res;
    string cur;
    vector<bool> used(q.size(), false);

    // �������в�ͬ������
    backtrack(res, cur, used);

    // ���������ļ�
    ofstream out("output.txt");
    if (!out.is_open()) exit(2);

    // ������в�ͬ������
    for (const auto& e : res) {
        out << e << endl;
    }

    in.close();
    out.close();
    return 0;
}
