#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int INF = 0x3f3f3f3f;

int n, m;
int h[N], e[N], ne[N], idx;
int f[305][305];
int w[N];
int res = -INF;

int max(int a, int b)
{
    return a > b ? a : b;
}

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

// f[i][j] = max(f[i][j], )
void dfs(int u, int tot)
{
    if (tot <= 0) return;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        for (int k = 0; k < tot; k ++ )
        {
            f[j][k] = f[u][k] + w[j]; // 注意这里是 w[j] 而不是 w[u]
        }

        // 当选取了 u 之后， tot 就减去了 1;
        // 所以对于 u 的子节点， tot 的值少了1;
        dfs(j, tot - 1); 
        for (int k = 1; k <= tot; k ++ )
        {
            f[u][k] = max(f[u][k], f[j][k - 1]);
            res = max(f[u][k], res);
        }
    }
}

int main()
{
    memset(h, -1, sizeof(h));

    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
        int a;
        cin >> a >> w[i];
        add(a, i);
    }
    
    dfs(0, m);

    cout << res << endl;

    return 0;
}