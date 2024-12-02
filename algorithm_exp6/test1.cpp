#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

vector<int> cost; //每个任务所花费时间
int n, k;
int sum; //所有任务花费时间之和

struct State {
	State(int k)
		:machine_time(k,0)
	{
	}
	vector<int> machine_time; //每个机器需要工作的时间
	int sum_time = 0; //已遍历的任务时间之和
	int x = -1; //从0号任务开始选到了哪个任务
	int actual_time = 0; //目前需要时间 
	int est_time = -1;    //估计最小时间
	
	//为了实现小根堆，运算符重载
	bool operator<(const State& other) const
	{
		return est_time > other.est_time;
	}
};

//得到机器中最大工作时间
int GetMaxTime(const vector<int>& v)
{
	int m = 0;
	for (int i = 0; i < v.size(); i++)
		m = max(m, v[i]);
	return m;
}
//获取估计时间
void GetEstTime(State& st)
{
	int m = st.machine_time[0];
	for (int i = 0; i < k; i++)
		m = min(m, st.machine_time[i]);
	st.est_time = max(st.actual_time, m + (sum - st.sum_time)/k);
}

int bfs()
{
	priority_queue<State> heap;
	State init(k);
	heap.push(init);
	while (!heap.empty())
	{
		auto t = heap.top(); heap.pop();
		int u = t.x + 1;
		if (u >= n)
		{
			return t.actual_time;
		}
		
		//扩展状态
		for (int i = 0; i < k; i++)
		{
			State new_state(k);
			new_state.machine_time = t.machine_time;
			new_state.x = u;
			new_state.machine_time[i] += cost[u];
			new_state.actual_time = GetMaxTime(new_state.machine_time);
			new_state.sum_time = t.sum_time + cost[u];
			GetEstTime(new_state);
			heap.push(new_state);
		}
	}
	return -1;
}

int main()
{
	ifstream in("input.txt");
	if (!in.is_open())
	{
		cout << "input.txt文件打开失败" << endl;
		exit(1);
	}
	in >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int t;
		in >> t;
		cost.push_back(t);
		sum += t;
	}
	in.close();
	ofstream out("output.txt");
	if (!out.is_open()) {
		cout << "output.txt文件打开失败" << endl;
		exit(1);
	}
	out << bfs() << endl;
	out.close();
	return 0;
}