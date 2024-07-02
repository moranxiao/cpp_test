#include <iostream>


using namespace std;


//直接插入排序
void InsertSort(int a[],int sz)
{
    for (int i = 1; i < sz; i++)
    {
        int x = a[i];
        int j = i - 1;
        while (j >= 0 && x < a[j])
        {
            swap(a[j], a[j + 1]);
            j--;
        }
    }
}

//快速排序
void qsort(int a[], int l, int r)
{
    if (l >= r) return;
    int x = a[(l + r + 1) >> 1];
    int i = l - 1, j = r + 1;
    while (i < j)
    {
        do { i++; } while (a[i] < x);
        do { j--; } while (a[j] > x);
        if (i < j) swap(a[i], a[j]);
    }
    qsort(a, l, i - 1);
    qsort(a, i, r);
}

//冒泡排序
void BubbleSort(int a[],int sz)
{
    for (int i = 0; i < sz - 1; i++)
    {
        for (int j = 1; j < sz - i; j++)
        {
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
        }
    }
}

//选择排序
void SelectSort(int a[], int sz)
{
    for (int i = 0; i < sz - 1; i++)
    {
        int t = i;
        for (int j = i; j < sz; j++)
        {
            if (a[t] > a[j]) t = j;
        }
        swap(a[i], a[t]);
    }
}

//归并排序
void MergeSort(int a[], int l, int r)
{
    if (l >= r) return;
    int mid = (l + r) >> 1;
    MergeSort(a, l, mid);
    MergeSort(a, mid + 1, r);
    int i = l, j = mid + 1;
    int* tmp = new int[r -l+1], k = 0;
    while (i <= mid && j <= r)
    {
        if (a[i] > a[j]) tmp[k++] = a[j++];
        else  tmp[k++] = a[i++];
    }
    while (i <= mid)
    {
        tmp[k++] = a[i++];

    }
    while (j <= r)
    {
        tmp[k++] = a[j++];
    }
    for (int i = l; i <= r; i++)
    {
        a[i] = tmp[i - l];
    }
    delete[] tmp;
}

//堆排序
void down(int a[],int i,int sz)
{
    int tmp = i;
    if (i * 2 + 1 <= sz && a[tmp] < a[i * 2 + 1]) tmp = i * 2 + 1;
    if (i * 2 <= sz && a[tmp] < a[i * 2]) tmp = i * 2;
    if (tmp != i)
    {
        swap(a[tmp], a[i]);
        down(a,tmp,sz);
    }
}
//元素从下标1开始
void HeapSort(int a[], int sz)
{
    for (int i = sz / 2; i; i--)
    {
        down(a, i, sz);
    }
    for (int i = sz; i > 1; i--)
    {
        swap(a[1], a[i]);
        down(a, 1, i - 1);
    }
}
