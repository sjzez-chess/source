#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int n, m ,s;
int h[N], e[N], ne[N], idx;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

int depth[N], fa[N][22], lg[N];
void dfs(int now, int father)
{
    fa[now][0] = father; depth[now] = depth[father] + 1;
    for (int i = 1; i <= lg[depth[now]]; i ++ )
    {
        fa[now][i] = fa[fa[now][i - 1]][i - 1];
    }
    for (int i = h[now]; i != -1; i = ne[i])
    {
        if (e[i]!= father)
        {
            dfs(e[i], now);
        }
    }
}

inline int LCA(int x, int y)
{
    if (depth[x] < depth[y]) swap(x, y);
    while (depth[x] > depth[y])
        x = fa[x][lg[depth[x] - depth[y]] - 1];
    if (x == y) return x;
    for (int k = lg[depth[x]] - 1; k >= 0; k -- )
    {
        if (fa[x][k] != fa[y][k])
            x = fa[x][k], y = fa[y][k];
    }
    return fa[x][0];
}

int main()
{
    memset(h, -1, sizeof(h));

    cin >> n >> m >> s;
    for (int i = 1; i <= n - 1; i ++ )
    {
        int x, y;
        cin >> x >> y;
        add(x, y); add(y, x);
    }

    for (int i = 1; i <= n; i ++ )
    {
        lg[i] = lg[i - 1] + (1 << lg[i - 1] == i);
    }

    dfs(s, 0);

    for (int i = 1; i <= m; i ++ )
    {
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << endl;
    }

    return 0;
}