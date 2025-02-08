class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp(n+1);
            dp[0] = 0;
            int ans = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                dp[i+1] = 1;
                for(int j = 0; j < i; j++)
                {
                    if(nums[j] < nums[i])
                    dp[i+1] = max(dp[i+1],dp[j+1] + 1);
                }
                ans = max(ans,dp[i+1]);
            }
            return ans;
        }
    };