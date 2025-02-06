class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            vector<bool> dp(2e4+10,false);
            dp[0] = true;
            int sum = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                for(int j = sum; j >= 0; --j)
                {
                    if(dp[j])
                        dp[j+nums[i]] = true;
                }
                sum += nums[i];
            }
            if(sum % 2 != 0) return false;
            return dp[sum/2];
        }
    };