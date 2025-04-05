#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(26,0);
    int m1 = 0,m2;
    int idx1 = -1,idx2 = -1;
    for(auto e : s) 
    {
        cnt[e-'a']++;
    }
    for(int i = 0; i < 26; i++)
    {
        if(cnt[i] > m1)
        {
            m2 = m1;
            idx2 = idx1;
            m1 = cnt[i];
            idx1 = i;
        }
        else if(cnt[i] > m2)
        {
            m2 = cnt[i];
            idx2 = i;
        }
    }
    if(m1 - 1 > n - m1) cout << "no" << endl;
    else{
        cout << "yes" << endl;
        string ans;
        for(int i = 0; i < m1 - m2 - 1; i++)
        {
            ans += idx1 + 'a';
            cnt[idx1]--;
            for(int j = 0; j < 26; j++)
            {
                if(j != idx1 && j != idx2 && cnt[j] != 0)
                {
                    ans += j + 'a';
                    cnt[j]--;
                    break;
                }
            }
        }
        for(int i = 0; i < cnt[idx1]; i++)
        {
            ans += idx1 + 'a';
            for(int j = 0; j < 26; j++)
            {
                if(j != idx1 && cnt[j] != 0)
                {
                    ans += j + 'a';
                    cnt[j]--;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}