#include <iostream>
#include <functional>
#include <array>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        auto arrayHash = [fn = hash<int>()](array<int,26> arr)->size_t
        {
            return accumulate(arr.begin(),arr.end(),0u,[&](size_t acc,int num)
            {
                return (acc << 1) ^ fn(num);
            });
        };
        unordered_map<array<int,26>,vector<string>, decltype(arrayHash)> hash(20,arrayHash);
        
        for(auto& e1 : strs)
        {
            array<int,26> count{};
            for(auto& e2 : e1)
            {
                count[e2-'a']++;
            } 
            hash[count].push_back(e1);
        }
        vector<vector<string>> ans;
        for(auto& e : hash)
        {
            ans.push_back(e.second);
        }
        return ans;
    }
int main()
{
    // function<int(int,int)> test = [x = 1](int y,int z){return x+y+z;};
    // cout << test(3,4) << endl;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = groupAnagrams(strs);
    for(auto& e1 : res)
    {
        for(auto & e2 : e1)
        {
            cout << e2 << "  ";
        }
        cout << endl;
    }
    return 0;
}