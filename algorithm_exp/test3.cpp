#include <iostream>
#include <fstream>

using namespace std;

const int N = 1e3 + 10;
const char table[3][3] = { {'a','b','a'} ,{'c','b','a'}, {'a','c','c'}};
// 字符 'a', 'b', 'c' 对应 0, 1, 2
int dp[N][N][3]; //dp[i][j][k] 区间i~j 结果为a或b或c的情况个数
int main()
{
	ifstream in("input.txt");
	if (!in.is_open()) exit(1);
	
	string str;
	in >> str;
	int n = str.size();

	// 初始化单个字符的情况
	for (int i = 0; i < n; i++) {
		dp[i][i][str[i] - 'a'] = 1;  
	}


	for (int len = 2; len <= n; len++) {  
		for (int i = 0; i + len - 1 < n; i++) {  
			int j = i + len - 1;  
			for (int k = i; k < j; k++) { 
				// 合并左右区间的结果
				for (int x = 0; x < 3; x++) {  // 左区间结果
					for (int y = 0; y < 3; y++) {  // 右区间结果
						char result = table[x][y];  // 根据乘法表计算结果
						int t = result - 'a';  // 将结果字符映射为0, 1, 2
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