#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    sort(nums.begin(),nums.end());
    int ans = 0;
    for(int i = 0,j = 0; j < n; i++)
    {
        while(i < j && nums[j] - nums[i] > k) i++;
        while(j < n && nums[j] - nums[i] <= k) j++;
        ans = max(ans,j-i);
    }
    cout << ans << endl;
    return 0;
}