class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> nums;
        for(auto e : num)
        {
            while(!nums.empty() && nums.top() > e && k > 0)
            {
                nums.pop();
                k--;
            }
            nums.push(e);
        }
        while(k > 0)
        {
            k--;
            nums.pop();
        }
        stack<char> tmp;
        while(nums.size())
        {
            tmp.push(nums.top());
            nums.pop();
        }
        tmp.push('0');
        while(tmp.size() > 1 && tmp.top() == '0') tmp.pop();
        string res;
        while(tmp.size())
        {
            res += tmp.top();
            tmp.pop();
        }
        return res;
    }
};