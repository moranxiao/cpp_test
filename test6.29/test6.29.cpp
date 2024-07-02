#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
int g_val = 10000;

using namespace std;



int main()
{
	int m = 100;
	mutex mtx;
	vector<thread> v;
	v.resize(m);

	for (int i = 0; i < m; i++)
	{
		v[i] = thread([&]() {
			mtx.lock();
			while (g_val >= 0)
			{
				cout << g_val-- << endl;
			}
			mtx.unlock();
			});

	}
	for (int i = 0; i < m; i++)
	{
		v[i].join();
	}
	return 0;
}
