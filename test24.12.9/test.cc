class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() <= 2) return vector<vector<int>>();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i-1] == nums[i])
                continue;
            int l = i+1,r = nums.size()-1;
            while(l < r)
            {
                if(nums[i] + nums[l] + nums[r] > 0)
                {
                    r--;
                }
                else if(nums[i] + nums[l] + nums[r] < 0)
                    l++;
                else
                {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l-1] == nums[l]) l++;
                    while(l < r && nums[r+1] == nums[r]) r--;
                }
            }
        }
        return ans;
    }
};