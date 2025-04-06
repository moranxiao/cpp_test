#include <unordered_map>
class Solution {
public:
    int maxLength(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> hash;
        int ans = 0;
        for(int i = 0, j = 0; j < n; i++)
        {
            while(j < n && !hash.count(arr[j]))
            {
                hash.insert(arr[j]);
                j++;
            }
            ans = max(ans,j-i);
            while(arr[i] != arr[j])
            {
                hash.erase(arr[i]);
                i++;
            }
            hash.erase(arr[i]);
        }   
        return ans;
    }
};