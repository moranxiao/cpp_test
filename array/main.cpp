#include "array1.h"
#include "array2.h"

using namespace std;

int main()
{
    array1 arr1(50);
    cout << "arr1加1前:"  << endl; 
    for(int i = 0; i < 50; i++)
        cout << arr1[i] << ' ';
    for(int i = 0; i < 50; i++)
        arr1[i]+= 1;
    cout << endl <<  "arr1加1后:" << endl;  
    for(int i = 0; i < 50; i++)
        cout << arr1[i] << ' ';
    array2 arr2(15,20);
    cout << endl << "arr2加1前:" << endl;
    for(int i = 0; i < 15; i++)
    {
       for(int j = 0; j < 20; j++)
            cout << arr2[i][j] << ' ';
        cout << endl;
    }
    for(int i = 0; i < 15; i++)
    {
       for(int j = 0; j < 20; j++)
            arr2[i][j]++;
    }
    cout << endl << "arr2加1后:"  << endl;
    for(int i = 0; i < 15; i++)
    {
       for(int j = 0; j < 20; j++)
            cout << arr2[i][j] << ' ';
        cout << endl;
    }
    cout << arr1[50] << endl;
    return 0;
}