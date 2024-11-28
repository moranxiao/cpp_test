#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

//״̬����
struct State {
	vector<bool> st; //�洢��ѡ�ڵ�֮ǰ�ڵ��״̬����ѡ�벻ѡ
	int current_cut = 0; //��ǰ����
	int est_cut = 0; //�Ͻ磺ʵ�ʸ���+���Ƹ���
	int u = -1; //��ǰѡ�����ĸ���
	
	State(int n)
	{
		st.resize(n,false);
	}

	//����STL���ȶ��еıȽ�
	bool operator<(const State& other) const {
		return est_cut < other.est_cut;
	}

};
vector<vector<bool>> edges; //�ڽӱ�洢���б�
int n, m;

//��ȡ��u��n�����б�����������Щ���Ǹ�
int GetEstCut(int u)
{
	int m1 = 0, m2 = 0; //m1��ʾu~n����1~u-1�����ɵıߣ�m2��ʾu~n�еı�
	for (int i = u; i < n; i++)
	{
		for(int j = 0;j < n; j++)
		{
			if (edges[i][j])
			{
				if (j < u) m1++;
				else m2++;
			}
		}
	}
	return m1 + m2 / 2;
}

//����һ��״̬����һ���ڵ���չ��״̬
State GetState(const State& t,bool flag)
{
	int u = t.u + 1;
	int curr_cut = t.current_cut;
	vector<bool> st = t.st;
	st[u] = flag;
	for (int i = 0; i < u; i++)
	{
		if (st[i] != flag && edges[u][i]) curr_cut++;
	}
	State new_st(n);
	new_st.current_cut = curr_cut;
	new_st.u = u;
	new_st.st = st;
	new_st.est_cut = GetEstCut(u) + curr_cut;
	return new_st;
}

State bfs()
{
	priority_queue<State> heap;
	heap.push(State(n));
	while (heap.size())
	{
		auto t = heap.top(); heap.pop();
		if (t.u + 1 >= n) return t;
		heap.push(GetState(t,false));
		heap.push(GetState(t, true));
	}
}

int main()
{
	ifstream in("input.txt");
	if (!in.is_open())
	{
		cout << "δ��input.txt�ļ��ɹ�" << endl;
		return 1;
	}
	in >> n >> m;
	edges.resize(n);
	for (int i = 0; i < n; i++)
	{
		edges[i].resize(n);
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		in >> a >> b;
		--a, --b;
		edges[a][b] = edges[b][a] = true;
	}
	State t = bfs();
	
	ofstream out("output.txt");
	if (!out.is_open())
	{
		cout << "δ��onput.txt�ļ��ɹ�" << endl;
		return 2;
	}
	out << t.current_cut << endl;


	for (int i = 0; i < n; i++) {
		out << t.st[i] << " ";
	}
	out << endl; 
	return 0;
}