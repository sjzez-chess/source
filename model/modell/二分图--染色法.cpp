#include <bits/stdc++.h>

/*
用于判断是不是二分图
二分图定义： 可以把所有点划分到两边去 
一个图是二分图，当且仅当图中不含奇数环 ，如果不含有奇数环的话就一定是二分图 
*/
 
using namespace std;

const int N = 100010, M = 100010 * 2;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N];
//bool st[N];

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++ ;
}

bool dfs(int u, int c)
{
	color[u] = c;
	
	for(int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if(!color[j])
		{
			if(!dfs(j, 3 - c)) return false;
		}
		else if(color[j] == c) return false;
	}
	
	return true;
}
int main()
{
	cin >> n >> m;
	
	memset(h, -1, sizeof h);
	
	while (m -- )
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	
	bool flag = true;
	for (int i = 1; i <= n; i ++ )
	{
		if(!color[i])
		{
			if(!dfs(i, 1))
			{
				flag = false;
				break;
			}
		}
	}
	
	if (flag) cout << "Yes";
	else cout << "No";
	return 0;
}
