class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            unordered_map<int,int> hash;
            int prev = 0;
            hash[0] = 1;
            int ret = 0;
            for(auto e : nums)
            {
                prev += e;
                if(hash.count(prev-k))
                    ret += hash[prev-k];
                hash[prev] ++;
            }
            return ret;
        }
    };