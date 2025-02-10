class Solution {
    public:
        int rob(vector<int>& nums) {
            vector<vector<int>> dp(nums.size(), vector<int>(2));
            dp[0][0] = 0;
            dp[0][1] = nums[0];
            for(int i = 1; i < nums.size(); ++i)
            {
                dp[i][0] = max(dp[i-1][1],dp[i-1][0]);
                dp[i][1] = dp[i-1][0] + nums[i];
            }
            int n = nums.size();
            return max(dp[n-1][0],dp[n-1][1]);
        }
    };