#include <bits/stdc++.h>

using namespace std;

int lowbit(int x)
{
	return x & -x;
}
// 加值操作 
void modify(int x, int v)
{
	for (int i = x; i <= n; i += lowbit(i))
		a[i] += v;
}
// 查询操作 
int query(int x)
{
	int ret = 0;
	for (int i = x; i; i -= lowbit(i))
		ret += a[i];
	return ret;
}
//区间max 不能用树状数组

// 区间加 单点查询

// 区间加 区间查询 

// 区间加 区间和
int a[2][Max_n];

void change(int x, int v, int t)
{
	for(int i = x; i <= n; i += lowbit(i))
		a[t][i] += v;
} 

// 区间加 区间查
int query(int x)
{
	int ret = 0;
	for(int i = x; i ; i -= lowbit(i))
		ret 
 } 
int main()
{
	int ans = query(r) - query(l - 1);
	//////////////////////////////////////
	l = read(), r = read();
	
	change(l, (l - 1) * v, 0);
	change(r + 1, -(l - 1) * v, 0);
	change(l, v, 1);
	change(r + 1, -v, 1);
	change(r + 1, (r - l + 1) * v, 0);
	////////////////////////////////////////
	
	return 0;
}
