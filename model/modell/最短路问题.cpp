#include <bits/stdc++.h>

using namespace std;

const int N = 520;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

int dijkstra()
{
	memset(dist, 0x3f, sizeof(dist));//��ʼ�� 
	dist[1] = 0;
	
	for(int i = 0; i < n; i ++ )
	{
		int t = -1;                                         
		for(int j = 1; j <= n; j ++ )
		{
			if(!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		}
		
		st[t] = true;
		
		for(int j = 1; j <= n; j ++ )//��t���������� 
			dist[j] = min(dist[j], dist[t] + g[t][j]);
	}
	
	if(dist[n] == 0x3f3f3f3f) return -1;//˵���ǲ���ͨ�� 
	return dist[n];//���򷵻���С���� 
}

int main()
{
	cin >> n >> m;
	
	memset(g, 0x3f, sizeof(g));
	
	while(m -- )
	{
		int a, b ,c;
		cin >> a >> b >> c;
		g[a][b] = min(g[a][b], c);
	}
	
	int t = dijkstra();
	
	cout << t;
	
	return 0;
}
