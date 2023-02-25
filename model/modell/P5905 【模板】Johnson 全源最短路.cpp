#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 3e6, INF = 1e9;

int n, m;
int h[N], e[N], ne[N], idx, w[N];
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx ++ ; 
}

struct node
{
    int dis, id;
    bool operator<(const node & a) const {return dis > a.dis;}
    node(int d, int x)
    {
        dis = d, id = x;
    }
};

int cnt[N];
bool SPFA(int s)
{
    queue<int> q;
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    st[s] = true;
    q.push(s);
    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                    cnt[j] ++ ;
                    if (cnt[j] == n + 1) return false;
                }
            }
        }
    }
    return true;
}

int dis[N]; 
void dijkstra(int s)
{
    priority_queue<node> q;
    for (int i = 0; i <= n; i ++ )
        dis[i] = INF;
    memset(st, false, sizeof(st));
    dis[s] = 0;
    q.push(node(0, s));
    while (!q.empty())
    {
        int t = q.top().id;
        q.pop();
        if (st[t]) continue;
        st[t] = true;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dis[j] > dis[t] + w[i])
            {
                dis[j] = dis[t] + w[i];
                if (!st[j])
                {
                    q.push(node(dis[j], j));
                }
            }
        }
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(false);

    memset(h, -1, sizeof(h));

    cin >> n >> m;
    for (int i = 1; i <= m; i ++ )
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
 // 建立一个超级 0 点
    for (int i = 1; i <= n; i ++ ) 
        add(0, i, 0);

    if (!SPFA(0))
    {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i <= n; i ++ )
    {
        for (int j = h[i]; j != -1; j = ne[j])
        {
            w[j] += dist[i] - dist[e[j]];
        }
    }
    
    for (int i = 1; i <= n; i ++ )
    {
        dijkstra(i);
        long long ans = 0;
        for (int j = 1; j <= n; j ++ )
        {
            if (dis[j] == INF)
            {
                ans += j * INF;
            }
            else 
            {
                ans += j * (dis[j] + dist[j] - dist[i]);
            }
        }
        cout << ans << endl;
    }

    return 0;
}