#include <bits/stdc++.h>

using namespace std;

const int N = 510, M = 10010;

int n, m, k;
int dist[N], backup[N];
struct Edge
{
    int a, b ,c;
}edges[M];

int bellman_ford()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;

    for (int i = 0; i < k; i ++ )
    {
        memcpy(backup, dist, sizeof(dist));
        for (int j = 0; j < m; j ++ )
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].c;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }

    if (dist[n] > 0x3f3f3f3f / 2) return -1;
    return dist[n];
}

int main()
{
    cin >> n >> m >> k;

    for (int i = 0; i < m; i ++ )
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    int t = bellman_ford();

    if (t == -1) cout << "impossible";
    else cout << t << endl;
    return 0;
}