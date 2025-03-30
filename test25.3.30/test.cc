class Solution {
    public:
        string decodeString(string s) {
            string res;
            for(int i = 0; i < s.size(); i++)
            {
                if(isdigit(s[i]))
                {
                    int t = 0;
                    int j = i;
                    while(j < s.size() && isdigit(s[j]))
                        t = t * 10 + s[j++]-'0';
                    int cnt = 1;
                    j++;
                    i = j;
                    while(j < s.size())
                    {
                        if(s[j] == '[') cnt++;
                        else if(s[j] == ']')
                        {
                            cnt--;
                            if(cnt == 0)
                                break;
                        }
                        j++;
                    }
                    string tmp = decodeString(s.substr(i,j-i));
                    while(t--)
                    {
                        res += tmp;
                    }
                    i = j;
                }
                else res += s[i];
            }
            return res;
        }
    };