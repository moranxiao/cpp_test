#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
	multiset<int> s1({ 10,20,20,20,30,40,50 ,60 });
	multiset<int>::iterator lit = s1.lower_bound(20);
	multiset<int>::iterator rit = s1.upper_bound(50);
	while (lit != rit)
	{
		cout << *lit << ' ';
		lit++;
	}

	return 0;
}

