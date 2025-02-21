//class Solution {
//public:
//    vector<vector<int>> merge(vector<vector<int>>& intervals) {
//        vector<vector<int>> res;
//        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2) {
//            return v1[0] < v2[0];
//            });
//        size_t i = 0;
//        while (i < intervals.size())
//        {
//            int right = intervals[i][1];
//            size_t j = i + 1;
//            while (j < intervals.size() && intervals[j][0] <= right)
//            {
//                right = max(right, intervals[j][1]);
//                j++;
//            }
//            res.push_back(vector({ intervals[i][0],right }));
//            i = j;
//        }
//        return res;
//    }
//};

#include <iostream>

int main()
{
	int* a = new int[3];
	int* b = new int(0);
	delete[] b;

}