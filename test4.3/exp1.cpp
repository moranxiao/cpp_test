#include <iostream>

using namespace std;

//1.输出月份有多少天
bool is_leapyear(int y)
{
    if(y % 400 == 0 || ((y%100 != 0)&& (y%4 == 0)))
        return true;
    return false;
}

int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
    int year,month;
    cin >> year >> month;
    if(month == 2 && is_leapyear(year)) cout << days[month-1] +1 << endl;
    else cout << days[month-1] << endl;
    
    return 0;
}
