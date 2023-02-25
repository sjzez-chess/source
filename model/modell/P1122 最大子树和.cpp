#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;

int n;
int w[N];
int h[N], e[N], ne[N], idx;
int f[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

int dfs(int u, int father)
{
    f[u] = w[u];
    for (int i = h[u]; i != -1; i = ne[i])
    {
        if (e[i] == father) continue;
        dfs(e[i], u);
        if (f[e[i]] >= 1) f[u] += f[e[i]];
    }
}

int main()
{
    memset(h, -1, sizeof(h));

    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> w[i];
    }

    for (int i = 1; i < n; i ++ )
    {
        int a, b;
        cin >> a >> b;
        add (a, b), add(b, a);
    }

    dfs(1, -1);

    int res = -2147483647;
    for (int i = 1; i <= n; i ++ )
        res = max(res, f[i]);

    cout << res << endl;

    return 0;
}