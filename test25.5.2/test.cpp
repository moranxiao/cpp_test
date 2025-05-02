#include <iostream>
#include <vector>


using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--)
    {
        long long a, b;
        cin >> a >> b;
        if(a > b) swap(a,b);
        if(a != 1 || (a == 1 && b == 1))
        {
            cout << "NO" << endl;
        }
        else{
            bool flag = true;
            for(int i = 2; i <= b / i; ++i)
            {
                if(b % i == 0)
                {
                    flag = false;
                    break;
                }
            }
            if(flag) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}