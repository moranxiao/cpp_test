class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int l = 0,r = nums.size()-1;
            while(l < r)
            {
                int mid = (l + r) >> 1;
                if(nums[0] <= nums[mid])
                {
                    if(target > nums[mid]) l = mid+1;
                    else if(target < nums[l]) l = mid+1;
                    else r = mid;
                }
                else
                {
                    if(target <= nums[mid]) r = mid;
                    else if(target > nums[r])
                    {
                        r = mid;
                    }
                    else l = mid+1;
                }
            }
            if(nums[r] == target) return r;
            else return -1;
        }
    };