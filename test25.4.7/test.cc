#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--)
    {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        int cnt = 0;
        int ans = 0;
        for(auto e : s)
        {
            if(e == 'W')
            {
                cnt++;
                if(cnt >= 3) ans+=k;
                else ans++;
            }
            else{
                cnt = 0;
                ans--;
            }

        }
        cout << ans << endl;
    }
}