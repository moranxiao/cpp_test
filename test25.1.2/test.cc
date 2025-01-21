#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
int maxCount = 1;

void SearchCountMax(int* arr,int l,int r)
{
    if(r - l + 1 < maxCount) return;
    int mid = (l + r) >> 1;
    int i = l;
    while(arr[i] != arr[mid]) i++;
    int j = i;
    while(j <= r && arr[j] == arr[mid]) j++;
    if(j-i == maxCount) nums.push_back(arr[mid]);
    else if(j-i > maxCount) 
    {
        nums.clear();
        nums.push_back(arr[mid]);
        maxCount = j-i;
    }
    SearchCountMax(arr,l,i-1);
    SearchCountMax(arr,j,r);
}

void SearchCountMax(int* arr,int sz)
{
    sort(arr,arr+sz);
    SearchCountMax(arr,0,sz-1);
}

int main()
{
    int arr[] = {2,3,4,1,5,7,7,10,4,5,5,4,7};
    SearchCountMax(arr,sizeof(arr)/sizeof(int));
    cout << maxCount << endl;
    for(auto e : nums)
    {
        cout << e << endl;
    }
    return 0;
}