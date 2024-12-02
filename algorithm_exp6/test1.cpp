#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

vector<int> cost; //ÿ������������ʱ��
int n, k;
int sum; //�������񻨷�ʱ��֮��

struct State {
	State(int k)
		:machine_time(k,0)
	{
	}
	vector<int> machine_time; //ÿ��������Ҫ������ʱ��
	int sum_time = 0; //�ѱ���������ʱ��֮��
	int x = -1; //��0������ʼѡ�����ĸ�����
	int actual_time = 0; //Ŀǰ��Ҫʱ�� 
	int est_time = -1;    //������Сʱ��
	
	//Ϊ��ʵ��С���ѣ����������
	bool operator<(const State& other) const
	{
		return est_time > other.est_time;
	}
};

//�õ������������ʱ��
int GetMaxTime(const vector<int>& v)
{
	int m = 0;
	for (int i = 0; i < v.size(); i++)
		m = max(m, v[i]);
	return m;
}
//��ȡ����ʱ��
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
		
		//��չ״̬
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
		cout << "input.txt�ļ���ʧ��" << endl;
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
		cout << "output.txt�ļ���ʧ��" << endl;
		exit(1);
	}
	out << bfs() << endl;
	out.close();
	return 0;
}