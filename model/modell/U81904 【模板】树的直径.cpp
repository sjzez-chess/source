#include <bits/stdc++.h>

using namespace std;

#define int long long
                                                                                                                                                                                                                                                                                 
                                                                                                                                                                                                                                                                                 
const int N = 1e7;

int n;
int h[N], e[N], ne[N], w[N], idx;
int ans;

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

int dfs(int u, int father)
{
    int dist = 0;
    int d1 = 0, d2 = 0;

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j == father) continue;
        int d = dfs(j, u) + w[i];
        dist = max(dist, d);

        if (d >= d1) d2 = d1, d1 = d;
        else if (d > d2) d2 = d;
    }

    ans = max(ans, d1 + d2);

    return dist;
}

signed main()
{
    cin >> n;

    memset(h, -1, sizeof(h));

    for (int i = 1; i < n; i ++ )
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }

    dfs(1, -1);

    cout << ans << endl;

    return 0;
}