#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums; //存众数有哪些
int maxCount = 1; //存最大的重数

void SearchCountMax(int* arr,int l,int r)
{
    if(r - l + 1 < maxCount) return; //如果区间个数小于最大重数吗，没有必要处理了
    int mid = (l + r) >> 1;
    int i = l; //初始化i
    while(arr[i] != arr[mid]) i++; //找到第一个等于arr[mid]的元素
    int j = i;
    while(j <= r && arr[j] == arr[mid]) j++; //找到第一个不等于arr[mid]的元素
    if(j-i == maxCount) nums.push_back(arr[mid]); //如果重数是最大重数，则加入数组中
    else if(j-i > maxCount)  //如果比最大重数要多，更新最大重数，并且之前记录的众数都要删除
    {
        nums.clear(); //删除之前重数较小的数
        nums.push_back(arr[mid]);
        maxCount = j-i;
    }
    SearchCountMax(arr,l,i-1); //递归
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