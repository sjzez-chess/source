#include <bits/stdc++.h>
/*
1. 将所有边按权重从小到大排序
2. 枚举每条边ab，权重是c。
   如果ab不连通，就把ab这条边加入集合中
*/ 

using namespace std;

const int N = 200010;

int n, m, k; //n是点数， m是边数 
int p[N]; //并查集的父节点数组 

struct Edge //存储边 
{
	int a, b, w;
	
	bool operator< (const Edge &W)const
	{
		return w < W.w;
	}
}edges[N];

int find(int x) //并查集的核心操作 
{
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin >> n >> m >> k;	
	
	if(k > n)
	{
		cout << "No Answer";
	}
		
	for (int i = 0; i < m; i ++ )
	{
		int a, b, w;
		cin >> a >> b >> w;
		edges[i] = {a, b, w};
	}
	
	//排序 
	sort(edges, edges + m);
	
	//并查集初始化 
	for (int i = 1; i <= n; i ++ ) 
	{
		p[i] = i;
	}
	
	int res = 0, cnt = 0;// res存最小生成树的边权之和，cnt存加了多少条边 
	for (int i = 0; i < m; i ++ )
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
	
		a = find(a), b = find(b);
		if(a != b) //如果两个连通块不联通，就将两个连通块合并 
		{	
			p[a] = b;
			res += w;
			cnt ++ ;
		}
		if(cnt == n - k) // 切记 ：每连接一个就会少一个连通块！！！ 
		{
			cout << res;
			return 0;
		}
	}
	
	return 0;
}
