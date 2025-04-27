class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         * 
         * @param schedule int整型vector<vector<>> 
         * @return bool布尔型
         */
        bool hostschedule(vector<vector<int> >& schedule) {
            sort(schedule.begin(),schedule.end(),[](const vector<int>& v1,const vector<int>& v2){return v1[0] < v2[0];});
            for(size_t i = 0; i < schedule.size()-1; i++)
            {
                if(schedule[i][1] > schedule[i+1][0]) return false;
            }
            return true;
        }
    };