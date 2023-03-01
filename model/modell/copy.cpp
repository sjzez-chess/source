#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 4e6 + 10;

int n, m;
int e[M], ne[M], h[N], idx;
int root, dfn[N], low[N], stk[N], top, timestamp, dcc_cnt;
vector<int> dcc[N];

void add(int u, int v)
{
	e[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
}

void tarjan(int u, int root)
{
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u;
	if (u == root && !h[u])
	{
		dcc[++dcc_cnt].push_back(u);
		return;
	}

	for (int i = h[u]; i; i = ne[i])
	{
		int v = e[i];
		if (!dfn[v])
		{
			tarjan(v, root);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u])
			{
				++dcc_cnt;
				int y;
				do
				{
					y = stk[top--];
					dcc[dcc_cnt].push_back(y);
				} while (y != v);
				dcc[dcc_cnt].push_back(u);
			}
		}
		else
			low[u] = min(low[u], dfn[v]);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		if (u == v)
			continue;
		add(u, v), add(v, u);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i])
			tarjan(i, i);
	}

	printf("%d\n", dcc_cnt);
	for (int i = 1; i <= dcc_cnt; i++)
	{
		printf("%d ", dcc[i].size());
		for (int j = 0; j < dcc[i].size(); j++)
		{
			printf("%d ", dcc[i][j]);
		}
		printf("\n");
	}

	return 0;
}