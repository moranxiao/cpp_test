#include <iostream>

#include "FIFO.hpp"
#include "LRU.hpp"
using namespace std;
using namespace replace_pages;

void Print(const vector<int>& pages,const std::vector<std::vector<int>>& g,const std::vector<bool>& st,int miss_page_num)
{
	cout << "ҳ�����У�";
	for (size_t i = 0; i < pages.size(); i++)
		cout << pages[i] << " \t";
	cout << endl;

	for (int i = 0; i < g.size(); i++)
	{
		cout << i << "���ڴ�:  ";
		for (int j = 0; j < g[i].size(); j++)
		{

			if (g[i][j] == -1)
				cout << "��";
			else
				cout << g[i][j];
			cout << " \t";
		}
		cout << endl;
	}

	cout << "�Ƿ�ȱҳ:";
	for (size_t i = 0; i < st.size(); i++)
	{
		if (st[i]) cout << "�� \t";
		else cout << "�� \t";
	}
	cout << endl;
	cout << "ȱҳ�ʣ�" << miss_page_num << '/' << pages.size() << endl;
}

void TestFIFO()
{
	vector<int> pages = { 7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1 };
	vector<vector<int>> g;
	vector<bool> st;
	int miss_page_num = FIFO(pages, 4, g,st);
	Print(pages, g, st, miss_page_num);

}
void TestLRU()
{
	vector<int> pages = { 7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1 };
	vector<vector<int>> g;
	vector<bool> st;
	int miss_page_num = LRU(pages, 4, g, st);
	Print(pages, g, st, miss_page_num);

}

int main()
{
	//TestFIFO();
	TestLRU();
	return 0;
}