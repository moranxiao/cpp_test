#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> cnt(26,0);
    for(auto e : s)
    {
        cnt[e-'a']++;
    }
    int maxn = cnt[0],minn = -1;
    for(auto e : cnt)
    {
        if(e > maxn) maxn = e;
        if(e != 0)
        {
            if(minn == -1 || e < minn) minn = e;
        }
    }
    int num = maxn - minn;
    bool flag = true;
    for(int i = 2; i <= num / i; i++)
    {
        if(num % i == 0)
        {
            flag = false;
            break;
        } 
    }
    if(num == 0 || num == 1) flag = false;
    if(flag)
    {
        cout << "Lucky Word" << endl;
        cout << num << endl;
    }   
    else 
    {
        cout << "No Answer" << endl;
        cout << "0" << endl;
    }
    return 0;
}