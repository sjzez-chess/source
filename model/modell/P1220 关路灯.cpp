#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, c;
int a[55], b[55];
int sum[55];
int f[55][55][2];

int min(int a, int b)
{
    if (a > b)
        return b;
    return a;
}

int max(int a, int b)
{
    if (a < b)
        return b;
    return a;
}

signed main()
{
    memset(f, 0x3f, sizeof(f));
    cin >> n >> c;
    for (int i = 1; i <= n; i ++ ) 
    {
        cin >> a[i] >> b[i];
        sum[i] = sum[i - 1] + b[i];
    }
    f[c][c][0] = f[c][c][1] = 0;

    for (int len = 2; len <= n; len ++ )
    {
        for (int i = 1; i + len - 1 <= n; i ++ )
        {
            int j = i + len - 1; 
            f[i][j][0] = min(f[i + 1][j][0] + (a[i + 1] - a[i]) * (sum[i] + sum[n] - sum[j]), f[i + 1][j][1] + (a[j] - a[i]) * (sum[i] + sum[n] - sum[j]));
            f[i][j][1] = min(f[i][j - 1][0] + (a[j] - a[i]) * (sum[i - 1] + sum[n] - sum[j - 1]), f[i][j - 1][1] + (a[j] - a[j - 1]) * (sum[i - 1] + sum[n] - sum[j - 1]));
        }
    }
    int res = min(f[1][n][0], f[1][n][1]);

    cout << res << endl;

    return 0;
}