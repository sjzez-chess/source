#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int m, n;
int w[N], v[N], x;
int g[N][N];
int b[N], t;
int f[N];

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> w[i] >> v[i] >> x;
        t = max(t, x);
        b[x] ++ ;
        g[x][b[x]] = i;
    }

    for (int i = 1; i <= t; i ++ )
        for (int j = m; j >= 0; j -- )
            for (int k = 1; k <= b[i]; k ++ )
            {
                if (w[g[i][k]] <= j)
                    f[j] = max(f[j], f[j - w[g[i][k]]] + v[g[i][k]]);
            }

    cout << f[m];

    return 0;
}