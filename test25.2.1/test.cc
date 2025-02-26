class Solution {
    public:
        int findMin(vector<int>& nums) {
            int n = nums.size();
            if(nums[0] <= nums[n-1]) return nums[0];
            int l = 0, r = n-1;
            while(l < r)
            {
                int mid = (l + r) >> 1;
                if(nums[0] <= nums[mid])
                {
                    l = mid+1;
                }
                else r = mid;
            }
            return nums[r];
        }
    };