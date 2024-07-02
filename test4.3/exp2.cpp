#include <iostream>

using namespace std;

int power3(int x)
{
    return x*x*x;
}

long long power3(long long x)
{
    return x*x*x;
}

double power(double x)
{
    return x*x*x;
}

int main()
{
    cout << power(2) << endl;
    cout << power(2.1) << endl;
    cout << power(1e10) << endl;
    return 0;
}