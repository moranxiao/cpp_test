class Solution {
    static const int N = 110;
    int nums[N];
public:
    Solution()
    {
        for(int i = 1; i <= 100; i++)
        {
            nums[i] = i*i;
        }
    }
    int numSquares(int n) {
        vector<int> dp(n+1,0x3f3f3f3f);
        dp[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= 100; j++)
            {
                if(nums[j] > i) break;
                dp[i] = min(dp[i],dp[i-nums[j]] + 1);
            }
        }
        return dp[n];
    }
};