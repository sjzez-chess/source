#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int, int> PII;

const int N = 2e6 + 5;

int n, m, s;      // 点的数量
int h[N], w[N], e[N], ne[N], idx;       // 邻接表存储所有边
int dist[N];        // 存储所有点到1号点的距离
bool st[N];     // 存储每个点的最短距离是否已确定

// 求1号点到n号点的最短距离，如果不存在，则返回-1
void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, s});      // first存储距离，second存储节点编号

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

signed main()
{
    memset(h, -1, sizeof(h));

    cin >> n >> m >> s;

    for (int i = 1; i <= m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    dijkstra();

    for (int i = 1; i <= n; i ++ )
    {
        if (s == i) cout << 0 << " ";
        else if(dist[i] > 0x3f3f3f3f / 2) cout << 2147483647 << " ";
        else cout << dist[i] << " ";
    }

    return 0;
}