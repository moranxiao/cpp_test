#include <iostream>
#include <fstream>

using namespace std;

const int N = 1e3 + 10;
const char table[3][3] = { {'a','b','a'} ,{'c','b','a'}, {'a','c','c'}};
// �ַ� 'a', 'b', 'c' ��Ӧ 0, 1, 2
int dp[N][N][3]; //dp[i][j][k] ����i~j ���Ϊa��b��c���������
int main()
{
	ifstream in("input.txt");
	if (!in.is_open()) exit(1);
	
	string str;
	in >> str;
	int n = str.size();

	// ��ʼ�������ַ������
	for (int i = 0; i < n; i++) {
		dp[i][i][str[i] - 'a'] = 1;  
	}


	for (int len = 2; len <= n; len++) {  
		for (int i = 0; i + len - 1 < n; i++) {  
			int j = i + len - 1;  
			for (int k = i; k < j; k++) { 
				// �ϲ���������Ľ��
				for (int x = 0; x < 3; x++) {  // ��������
					for (int y = 0; y < 3; y++) {  // ��������
						char result = table[x][y];  // ���ݳ˷��������
						int t = result - 'a';  // ������ַ�ӳ��Ϊ0, 1, 2
						dp[i][j][t] += dp[i][k][x] * dp[k + 1][j][y];
					}
				}
			}
		}
	}
	ofstream out("output.txt");
	if (!out.is_open()) exit(2);

	out << dp[0][n-1][0] << endl;  

	in.close();
	out.close();
	return 0;
}