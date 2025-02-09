class Solution {
    public:
        bool wordBreak(const string& s, vector<string>& wordDict) {
            unordered_set<string> hash;
            for(auto & e : wordDict)
                hash.insert(e);
            
            vector<bool> dp(s.size()+1);
            dp[0] = true;
            for(int i = 0; i < s.size(); i++)
            {
                for(int j = 0; j <= i; j++)
                {
                    dp[i+1] = dp[i+1] || (dp[j] && hash.find(s.substr(j,i-j+1)) != hash.end());       
                }
            }
            return dp[s.size()];
        }
    };