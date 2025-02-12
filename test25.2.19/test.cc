class Solution {
    public:
        static const int N = 50;
        int dp[N] = {0};
        int climbStairs(int n) {
            dp[0] = dp[1] = 1;
            for(int i = 2; i <= n; i++)
            {
                dp[i] = dp[i-1] + dp[i-2];
            }
            return dp[n];
        }
    };