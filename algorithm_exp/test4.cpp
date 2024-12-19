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
        res.push_back(cur);  // 完成一个排列
        return;
    }

    for (int i = 0; i < q.size(); i++) 
    {
        if (used[i]) continue;  // 如果已经使用过该元素，跳过

        // 防止重复排列
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
    sort(q.begin(), q.end());  // 排序字符串

    vector<string> res;
    string cur;
    vector<bool> used(q.size(), false);

    // 生成所有不同的排列
    backtrack(res, cur, used);

    // 输出结果到文件
    ofstream out("output.txt");
    if (!out.is_open()) exit(2);

    // 输出所有不同的排列
    for (const auto& e : res) {
        out << e << endl;
    }

    in.close();
    out.close();
    return 0;
}
