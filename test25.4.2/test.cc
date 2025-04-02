class Solution {
    public:
    
        pair<int,int> ExtendStr(const string& s,int l,int r)
        {
            while(l >= 0 && r < s.size() && s[l] == s[r])
            {
                l--;
                r++;
            }
            return {l+1,r-1};
        }
    
        string longestPalindrome(string s) {
            int n = s.size();
            int l = 0, r = 0;
            for(int i = 0; i < n-1; i++)
            {
                auto [l1,r1] = ExtendStr(s,i-1,i+1);
                auto [l2,r2] = ExtendStr(s,i,i+1);
                if(r1-l1 > r-l)
                {
                    r = r1;
                    l = l1;
                }
                if(r2-l2 > r-l)
                {
                    r = r2;
                    l = l2;
                }
            }
            return s.substr(l,r-l+1);
        }
    };