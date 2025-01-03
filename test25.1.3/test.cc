class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        if(nums.size() <= 1) return nums;
        int l = -1,r = nums.size();
        while(l < r)
        {
            do{ l++; }while(l < r && nums[l] % 2 == 0);
            do{ r--; }while(l < r && nums[r] % 2 == 1);
            if(l < r)  swap(nums[l],nums[r]);
        }
        return nums;
    }
};