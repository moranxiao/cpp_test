class Solution {
    public:
        int maxEnvelopes(vector<vector<int>>& envelopes) {
            sort(envelopes.begin(),envelopes.end(),[](const vector<int>& v1,const vector<int>& v2)
            {
                return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] > v2[1]);
            });
            vector<int> dp = {envelopes[0][1]};
            for(int i = 1; i < envelopes.size(); i++)
            {
                int num = envelopes[i][1];
                int l = 0,r = dp.size()-1;
                while(l < r)
                {
                    int mid = (l + r) >> 1;
                    if(dp[mid] < num) l = mid+1;
                    else r = mid;
                }
                if(dp[r] < num) dp.push_back(num);
                else{
                    dp[r] = num;
                }
            }
            return dp.size();
        }
    };