#include <bits/stdc++.h>
/*
给n个数
求二进制表示里面1
的个数
*/ 
using namespace std;

int lowbit(int x)
{
	return x & -x;
}
int main()
{
	int n;
	cin >> n;
	while (n -- )
	{
		int x;
		cin >> x;
		
		int res = 0;
		while (x) x -= lowbit(x), res ++ ; // 每次减去x的最后一位1
		
		cout << res << ' '; 
	}
	return 0;
}
 
