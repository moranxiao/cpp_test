class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cnt[128] = {0};
        int res = 0;
        int i = 0,j = 0;
        for(;j < s.size(); j++)
        {
            cnt[s[j]]++;
            while(i < j && cnt[s[j]] > 1)
            {
                cnt[s[i]]--;
                i++;
            }
            res = max(res,j-i+1);
        }
        return res;
    }
};