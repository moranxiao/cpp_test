#pragma warning(disable : 4996)
#include <iostream>
#include <cstdio>

using namespace std;


int func(int n, int m)
{
	if (m > n) return 0; //如果要划分的集合数大于总元素个数，则有误
	if (m == 1 || n == m) return 1;  
	return func(n - 1, m - 1) + m * func(n - 1, m);
}

int main()
{
	int n, m, c;
	FILE* fp, * fp1;
	if ((fp = fopen("input.txt", "r")) == NULL) {
		printf("文件错误\n");
		exit(0);
	}
	fscanf(fp, "%d %d", &n, &m); //从文件中读取
	fclose(fp);

	c = func(n, m);
	if ((fp1 = fopen("output.txt", "w")) == NULL)
	{
		printf("文件错误\n");
		exit(0);
	}
	fprintf(fp1, "%d", c);//写入文件
	fclose(fp1);

	return 0;
}