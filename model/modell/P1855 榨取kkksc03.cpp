#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 300;

int n, m, t;
int v[N], w[N];
int f[N][N][N];
int ans;
signed main()
{
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> w[i] >> v[i];
    }
/*
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = m; j >= 0; j -- )
        {
            for (int k = t; k >= 0; k -- )
            {
                if (j + w[i] <= m && k + v[i] <= t)
                    ans = max(ans, f[i][j][k] = max(f[i - 1][j][k], f[i - 1][j + w[i]][k + v[i]] + 1));
                else 
                    ans = max(ans, f[i][j][k] = f[i - 1][j][k]);
            }
        }
    }
*/
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= m; j ++ )
        {
            for (int k = 1; k <= t; k ++ )
            {
                if (w[i] <= j && v[i] <= k)
                    ans = max(ans, f[i][j][k] = max(f[i - 1][j][k], f[i - 1][j - w[i]][k - v[i]]+ 1));
                else 
                    ans = max(ans, f[i][j][k] = f[i - 1][j][k]);
            }
        }
    }
    
    cout << ans;

    return 0;
}