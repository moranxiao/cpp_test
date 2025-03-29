//1 3 4 2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int flag = false;
    for(int i = n-1; i >= 0; i--)
    {
        int j = i+1;
        for(; j < n; j++)
        {
            if(nums[i] < nums[j])
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1,nums.end());
            break;
        }
    }
    if(!flag) reverse(nums.begin(),nums.end());
    for(auto e : nums)
        cout << e << ' ';
    return 0;
}