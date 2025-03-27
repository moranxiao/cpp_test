class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            int n = heights.size();
            stack<int> st;
            st.push(-1);
            int res = 0;
            for(int i = 0; i < n; ++i)
            {
                while(st.size() > 1 && heights[st.top()] > heights[i])
                {
                    int j = st.top();
                    st.pop();
                    res = max(res,heights[j]*(i-st.top()-1));
                }
                st.push(i);
            }
            while(st.size() > 1)
            {
                int j = st.top();
                st.pop();
                res = max(res,heights[j]*(n-st.top()-1));
            }
            return res;
        }
    };