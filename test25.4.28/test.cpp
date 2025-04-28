#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int sum  = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }
    vector<bool> dp(sum+1);
    dp[0] = true;
    for(int i = 0; i < n; ++i)
    {
        for(int j = nums[i]; j <= sum; j++)
        {
            dp[j] = dp[j-nums[i]];
        }
    }
    if(sum % 2 == 1 || !dp[sum/2])
    {
        cout << "false" << endl;
    }
    else cout << "true" << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")