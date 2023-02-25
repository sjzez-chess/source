#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 3500, INF = 0x3f3f3f3f;

int n, m, s, t;

struct edge
{
    int to, cap, rev; // 终点， 容量， 反向边
};
vector<edge> G[N]; // 图的邻接表表示 
bool used[N];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

inline void add(int from, int to, int cap) // 存边
{
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, 0, G[from].size() - 1});
}

inline int dfs(int v, int t, int f)
{
    if (v == t) return f;
    used[v] = true;
    for (register int i = 0; i < G[v].size(); ++ i )
    {
        edge &e = G[v][i];
        if (!used[e.to] && e.cap > 0)
        {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0)
            {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

inline int max_flow(int s, int t)
{
    int flow = 0;
    for (;;)
    {
        memset(used, 0, sizeof(used));
        int (f) = dfs(s, t, INF);
        if (f == 0) return flow;
        flow += f;
    }
}

signed main()
{
    n = read(), m = read(), s = read(), t = read();

    for (register int i = 1; i <= m; ++ i )
    {
        register int u, v, w;
        u = read(), v = read(), w = read();
        add(u, v, w);
        add(v, u, 0);
    }

    printf("%ld\n", max_flow(s, t));

    return 0;
}