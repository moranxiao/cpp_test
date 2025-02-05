class Solution {
    public:
        int iceBreakingGame(int num, int target) {
            int res = 0;
            for(int i = 2; i <= num; ++i)
            {
                res = (res + target)%i;
            }
            return res;
        }
    };