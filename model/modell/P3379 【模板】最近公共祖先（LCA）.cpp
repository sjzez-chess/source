#include <bits/stdc++.h>

using namespace std;

const int N = 5e6;

int n, m, s;
int h[N], e[N], ne[N], idx;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

int depth[N], fa[N][22], lg[N];
void dfs(int now, int fath) // now 表是当前节点， fath 表示他的父亲节点
{
    fa[now][0] = fath; depth[now] = depth[fath] + 1;
    for (int i = 1; i <= lg[depth[now]]; i ++ )
    {
        fa[now][i] = fa[fa[now][i - 1]][i - 1]; // 算法核心
    }   // now 的 2 ^ i 祖先等于 now ^ (i - 1) 祖先的 2 ^ (i - 1) 祖先
    for (int i = h[now]; i != -1; i = ne[i])
    {
        if (e[i] != fath)
        {
            dfs(e[i], now);
        }
    }
}

int LCA(int x, int y)
{
    if (depth[x] < depth[y]) swap(x, y); // 让 x 的深度 >= y 的深度 
    while (depth[x] > depth[y])
    {
        x = fa[x][lg[depth[x] - depth[y]] - 1]; // 先跳到同一深度
    }
    if (x == y) // 如果 x 是 y 的祖先，那他们的 LCA 肯定就是 x 了
    {
        return x;
    }
    for (int k = lg[depth[x]] - 1; k >= 0; k -- ) // 不断向上跳( lg 是常数优化)
    {
        if (fa[x][k] != fa[y][k]) // 因为我们要跳到他们 LCA 的下面一层， 所以他们肯定不相等， 就跳过去
        {
            x = fa[x][k], y = fa[y][k];
        }
    }
    return fa[x][0]; // 返回父节点
}

int main()
{
    memset(h, -1, sizeof(h));

    cin >> n >> m >> s;

    for (int i = 1; i <= n - 1; i ++ )
    {
        int x, y;
        cin >> x >> y;
        add(x, y), add(y, x);
    }

    for (int i = 1; i <= n; i ++ ) // 预先处理
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