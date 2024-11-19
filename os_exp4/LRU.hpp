#pragma once
#include <vector>

namespace replace_pages {
	//g[i][j]：内存中的第i块，在第j个页面到来后存储的页面
	//st[i]: 第i个页面到来时，是否缺页
	//方便打印
	//返回缺页数
	//采用堆栈方法，当查找一个页面时，如果页面在内存，将其提到顶部，其余向下压
	//如果页面不在，直接将页面放入顶部，其余向下压
	int LRU(const std::vector<int>& pages, int num, std::vector<std::vector<int>>& g, std::vector<bool>& st)
	{
		if (num <= 0 || pages.size() <= 0) return -1;

		int now_num = 0; //现在已用多少个页面
		int res = 0; //缺页数
		g.clear();
		g.resize(num);
		st.clear();
		st.resize(pages.size());
		//根据第一个页面 初始化g
		for (int i = 0; i < num; i++)
		{
			g[i].push_back(-1);
		}
		g[0][0] = pages[0];
		st[0] = true;
		now_num = 1;
		res = 1;
		//遍历将到来的页面
		for (size_t i = 1; i < pages.size(); i++)
		{
			st[i] = true;
			int t = -1;
			for (int j = 0; j < num; j++)
			{
				g[j].push_back(g[j].back());
				if (g[j][i] == pages[i])
				{
					st[i] = false;
					t = j;
				}
			}
			//如果缺页
			if (st[i])
			{
				res++;
				//新页面压入栈顶，其他页面向下移动
				for (int j = now_num; j > 0; j--)
					g[j][i] = g[j - 1][i];
				g[0][i] = pages[i];
				if(now_num < num-1)
					now_num++;
			}
			//如果不缺页
			else
			{
				//将匹配到的页面移入栈顶，在此页面之上的页面向下压
				for (int j = t; j > 0; j--)
				{
					g[j][i] = g[j - 1][i];
				}
				g[0][i] = pages[i];
			}
		}
		return res;
	}
}