#include <bits/stdc++.h>

using namespace std;

const int N = 200;

int n, p;
int h[N], e[N], ne[N], idx;
int f[N][N];
int a[N], b[N];
int root;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

int dfs(int u)
{
    int temp; int sum = 1;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int v = e[i];
        temp = dfs(v); sum += temp;
        for (int j = sum; j >= 1; j -- )
            for (int k = 1; k < j; k ++ )
                f[u][j] = min(f[u][j], f[u][j - k] + f[v][k] - 1);
    }
    return sum;
}

int main()
{
    memset(h, -1, sizeof(h));

    cin >> n >> p;
    for (int i = 1; i < n; i ++ )
    {
        int x, y;
        cin >> x >> y;
        a[x] ++ , b[y] = 1;
        add(x, y);
    }

    memset(f, 0x3f, sizeof(f));

    for (int i = 1; i <= n; i ++ )
    {
        if (!b[i]) root = i;
        f[i][1] = a[i];
    }

    dfs(root);

    int ans = f[root][p];

    for (int i = 1; i <= n; i ++ )
    {
        if (f[i][p] < ans)  ans = f[i][p] + 1;
    }

    cout << ans << endl;

    return 0;
}