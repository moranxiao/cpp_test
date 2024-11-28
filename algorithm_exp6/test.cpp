#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

//状态对象
struct State {
	vector<bool> st; //存储所选节点之前节点的状态，即选与不选
	int current_cut = 0; //当前割数
	int est_cut = 0; //上界：实际割数+估计割数
	int u = -1; //当前选到了哪个点
	
	State(int n)
	{
		st.resize(n,false);
	}

	//用于STL优先队列的比较
	bool operator<(const State& other) const {
		return est_cut < other.est_cut;
	}

};
vector<vector<bool>> edges; //邻接表存储所有边
int n, m;

//获取从u到n的所有边数，假设这些都是割
int GetEstCut(int u)
{
	int m1 = 0, m2 = 0; //m1表示u~n中与1~u-1所连成的边，m2表示u~n中的边
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

//用于一个状态向下一个节点扩展出状态
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
		cout << "未打开input.txt文件成功" << endl;
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
		cout << "未打开onput.txt文件成功" << endl;
		return 2;
	}
	out << t.current_cut << endl;


	for (int i = 0; i < n; i++) {
		out << t.st[i] << " ";
	}
	out << endl; 
	return 0;
}