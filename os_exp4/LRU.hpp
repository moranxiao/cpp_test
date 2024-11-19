#pragma once
#include <vector>

namespace replace_pages {
	//g[i][j]���ڴ��еĵ�i�飬�ڵ�j��ҳ�浽����洢��ҳ��
	//st[i]: ��i��ҳ�浽��ʱ���Ƿ�ȱҳ
	//�����ӡ
	//����ȱҳ��
	//���ö�ջ������������һ��ҳ��ʱ�����ҳ�����ڴ棬�����ᵽ��������������ѹ
	//���ҳ�治�ڣ�ֱ�ӽ�ҳ����붥������������ѹ
	int LRU(const std::vector<int>& pages, int num, std::vector<std::vector<int>>& g, std::vector<bool>& st)
	{
		if (num <= 0 || pages.size() <= 0) return -1;

		int now_num = 0; //�������ö��ٸ�ҳ��
		int res = 0; //ȱҳ��
		g.clear();
		g.resize(num);
		st.clear();
		st.resize(pages.size());
		//���ݵ�һ��ҳ�� ��ʼ��g
		for (int i = 0; i < num; i++)
		{
			g[i].push_back(-1);
		}
		g[0][0] = pages[0];
		st[0] = true;
		now_num = 1;
		res = 1;
		//������������ҳ��
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
			//���ȱҳ
			if (st[i])
			{
				res++;
				//��ҳ��ѹ��ջ��������ҳ�������ƶ�
				for (int j = now_num; j > 0; j--)
					g[j][i] = g[j - 1][i];
				g[0][i] = pages[i];
				if(now_num < num-1)
					now_num++;
			}
			//�����ȱҳ
			else
			{
				//��ƥ�䵽��ҳ������ջ�����ڴ�ҳ��֮�ϵ�ҳ������ѹ
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