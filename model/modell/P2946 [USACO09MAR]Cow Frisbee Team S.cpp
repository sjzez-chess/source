#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e8;

const int N = 2005;

int n, F;
int cow[N], f[N][N];

signed main()
{
    cin >> n >> F;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> cow[i];
        cow[i] %= F;
    }
    for (int i = 1; i <= n; i ++ ) f[i][cow[i]] = 1;
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 0; j < F; j ++ )
        {
            f[i][j] = ( (f[i][j] + f[i - 1][j]) % mod + f[i - 1][(j - cow[i] + F) % F] ) % mod;
            //f[i][j] = ((f[i][j] + f[i - 1][j]) % INF + f[i - 1][(j - cow[i] + F) % F]) % INF;
        }
    }

    cout << f[n][0];
    return 0;
}