#pragma once
#include <list>
#include <vector>

namespace replace_pages {
	//g[i][j]���ڴ��еĵ�i�飬�ڵ�j��ҳ�浽����洢��ҳ��
	//st[i]: ��i��ҳ�浽��ʱ���Ƿ�ȱҳ
	//�����ӡ
	//����ȱҳ��
	int FIFO(const std::vector<int>& pages, int num,std::vector<std::vector<int>>& g,std::vector<bool>& st)
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
			for (int j = 0; j < num; j++)
			{
				g[j].push_back(g[j].back());
				if (g[j][i] == pages[i])
				{
					st[i] = false;
				}
			}
			//���ȱҳ
			if (st[i])
			{
				res++;

				//�ڴ�δ������ֱ���ں������
				if (now_num < num)
				{
					g[now_num][i] = pages[i];
					now_num++;
				}
				//���������ƶ�����
				else
				{
					for (int j = 0; j < num - 1; j++)
						g[j][i] = g[j + 1][i];
					g[num - 1][i] = pages[i];
				}
			}
		}
		return res;
	}
}