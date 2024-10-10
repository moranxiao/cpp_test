#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdio>

using namespace std;

const int N = 1e3 + 10;

long long f[N][N]; //�洢״̬
long long q[N]; //�洢�߳�
int n = 1;

//��ȡ����
void GetData()
{
	ifstream file("input.txt");
	if (!file.is_open()) {
		std::cerr << "Failed to open the file." << std::endl;
		exit(1);
	}
	while (file >> q[n])
	{
		n++;
	}
	n--;
	file.close();
}
//����״̬
void dp()
{
	for (int len = 3; len <= n; len++)
	{
		for (int i = 1; i + len-1 <= n; i++)
		{
			int j = i + len - 1;
			f[i][j] = 1e13; //��Ϊһ���������
			for (int k = i + 1; k < j; k++)
			{
				f[i][j] = min(f[i][j], f[i][k] + f[k][j] + q[i] * q[k] * q[j]); //״̬ת��
			}
		}
	}
}
//��������������������Щ״̬ת�Ƶ�
void dfs(int l,int r,ofstream& file)
{
	char buffer[256];
	if (r - l + 1 <= 3)
	{
		int sz = snprintf(buffer,sizeof(buffer)-1,"[A%d]U[A%d]\n", l, r - 1);
		file << buffer;
		return;
	}
	for (int k = l + 1; k < r; k++)
	{
		if (f[l][r] == f[l][k] + f[k][r] + q[l] * q[r] * q[k])
		{
			dfs(l, k, file);
			dfs(k, r, file);
			int sz = snprintf(buffer, sizeof(buffer), "[A%d~A%d]U[A%d~A%d]\n", l, k - 1, k, r - 1);
			file << buffer;
			break;
		}
	}
}
//��ȡת��·��
void GetPath(ofstream& file)
{
	dfs(1, n,file);
}
//������
void OutToFile()
{
	ofstream file("output.txt");
	file.imbue(std::locale("en_US.UTF-8"));
	GetPath(file);
	file << "result:" << f[1][n];
	file.close();

}
int main()
{
	GetData();
	dp();
	OutToFile();
	return 0;
}