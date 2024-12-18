class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int res = min(height[l],height[r]) * (r-l);
        while(l < r)
        {
            if(height[l] < height[r])
            {
                int tmp = height[l];
                while(l < r && height[l] <= tmp)
                {
                    l++;
                }
            }
            else
            {
                int tmp = height[r];
                while(l < r && height[r] <= tmp)
                {
                    r--;
                }
            }
            res = max(res,min(height[l],height[r])*(r-l));
        }
        return res;
    }
};