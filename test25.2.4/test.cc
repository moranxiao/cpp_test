class Solution {
    public:
        int longestValidParentheses(string s) {
            int n = s.size();
            vector<int> dp(n+1,0);
            int ans = 0;
            for(int i = 0; i < n; i++)
            {
                if(s[i] == ')' && i-dp[i]-1 >= 0 && s[i-dp[i]-1] == '(') 
                {
                    dp[i+1] = dp[i] + 2;
                    if(i-dp[i]-2 >= 0) dp[i+1] += dp[i-dp[i]-1];
                    ans = max(ans,dp[i+1]);
                }    
            }
            return ans;
        }
    };