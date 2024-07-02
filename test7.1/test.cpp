#include <thread>
#include <iostream>
#include <vector>
#include <condition_variable>

using namespace std;



int main()
{
	int i = 0;
	int n = 100;
	mutex mtx;
	condition_variable cv;
	thread t1([&]() {
		while (i <= n)
		{
			unique_lock<mutex> lock(mtx);
			cv.wait(lock, [&]()->bool {return i % 2; });
			cout << this_thread::get_id() << ':' << i++ << endl;
			cv.notify_one();
		}
	});
	thread t2([&]() {
		while (i <= n)
		{
			unique_lock<mutex> lock(mtx);
			cv.wait(lock, [&]()->bool {return !(i % 2); });
			cout << this_thread::get_id() << ':' << i++ << endl;
			cv.notify_one();
		}
	});

	this_thread::sleep_for(chrono::seconds(2));
	cout << "t1:" << t1.get_id() << endl;
	cout << "t2:" << t2.get_id() << endl;

	t1.join();
	t2.join();

	return 0;
}