#include <bits/stdc++.h>
/*
��n����
������Ʊ�ʾ����1
�ĸ���
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
		while (x) x -= lowbit(x), res ++ ; // ÿ�μ�ȥx�����һλ1
		
		cout << res << ' '; 
	}
	return 0;
}
 
