class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int minPrice = 1e4+10;
            int ret = 0;
            for(int i = 0; i < prices.size(); i++)
            {
                minPrice = min(minPrice,prices[i]);
                ret = max(ret,prices[i]-minPrice);
            }
            return ret;
        }
    };