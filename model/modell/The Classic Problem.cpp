#include <bits/stdc++.h>

using namespace std;

#define int unsigned long long

typedef pair<int, int> PII;

const int N = 1e5 + 5;

int n, m;
int s, t;
int h[N], e[N], ne[N], idx, w[N];
int dist[N], lg[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

int Dijkstra(int s)
{
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1}); // 先将起点放进去

    while (heap.size())
    {
        auto t = heap.top(); // 找到距离最小的点
        heap.pop();

        int ver = t.second, distance = t.first;
        if (st[ver]) continue; // 如果被更新过就看下一个

        // 否则就用这个点更新所有点
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                // 如果更新成功的话，就将这个点放到新的里面去
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] > 0x3f3f3f3f / 2) return -1;
    return dist[n];
}

signed main()
{
    memset(h, -1, sizeof(h));

    lg[0] = 1;
    for (int i = 1; i <= 1000; i ++ )
    {
        lg[i] = lg[i - 1] * 2;
    }

    cin >> n >> m;
    for (int i = 1; i <= m; i ++ )
    {
        int u, v, val;
        cin >> u >> v >> val;
        add(u, v, lg[val]), add(v, u, lg[val]);
    }
    cin >> s >> t;

    int ans = Dijkstra(s);

    if (ans > 0x3f3f3f3f / 2) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}