// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         if(nums.size() <= 2) return vector<vector<int>>();
//         vector<vector<int>> ans;
//         sort(nums.begin(),nums.end());
//         for(int i = 0; i < nums.size(); i++)
//         {
//             if(i > 0 && nums[i-1] == nums[i])
//                 continue;
//             int l = i+1,r = nums.size()-1;
//             while(l < r)
//             {
//                 if(nums[i] + nums[l] + nums[r] > 0)
//                 {
//                     r--;
//                 }
//                 else if(nums[i] + nums[l] + nums[r] < 0)
//                     l++;
//                 else
//                 {
//                     ans.push_back({nums[i],nums[l],nums[r]});
//                     l++;
//                     r--;
//                     while(l < r && nums[l-1] == nums[l]) l++;
//                     while(l < r && nums[r+1] == nums[r]) r--;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// #include <iostream>

// using namespace std;

// struct Test{
//     void func()
//     {
//         cout << "you can see me!" << endl;
//     }
// };

// int main()
// {
//     Test* ptr = nullptr;
//     ptr->func();
//     return 0;
// }


#include <iostream>
using namespace std;

class MyClass {
public:
    void hello() {
        cout << "Hello, World!" << endl;
    }
};

int main() {
    MyClass obj;
    
    // 定义成员函数指针
    void (MyClass::*funcPtr)() = &MyClass::hello;
    
    // 通过成员函数指针调用成员函数
    (obj.*funcPtr)();  // 输出：Hello, World!
    
    return 0;
}