#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int la, lb;
char a[N], b[N]; // 两个字符串
int Next[N];// 存储 border 

// 求一个小字符串在大字符串中出现的所有头坐标位置
int main(){
	cin >> a + 1 >> b + 1;
	// Next 的匹配过程，从大 border 到 小border
	// O(n) 时间复杂度，可以使用势能来分析复杂度
	la = strlen(a + 1);
	lb = strlen(b + 1);

	for (int i = 2, j = 0; i <= lb; i ++ )
	{
		while (j && b[i] != b[j + 1]) j = Next[j];
		if (b[i] == b[j + 1]) j ++ ;
		Next[i] = j;
	}
	// KMP 的匹配过程
	// O(n + m) 时间复杂度 
	for (int i = 1, j = 0; i <= la; i ++ )
	{
		while (j && a[i] != b[j + 1]) j = Next[j];
		if(a[i] == b[j + 1])
		{
			j ++ ;
		}
		if(j == lb)
		{
			// 输出答案 
			cout << i - lb + 1  << endl;
			j = Next[j];// 继续求下一个答案，直接跳当前长度最大 border
		}
	}

	for (int i = 1; i <= lb; i ++ ) cout << Next[i] << " ";

	return 0;
}
