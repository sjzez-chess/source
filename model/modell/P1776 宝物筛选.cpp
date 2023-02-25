#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int n, W;
int v[N], w[N], s[N];
int f[N];

int main()
{
/*
    cin >> n >> W;
    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i] >> s[i];

    int res = -0x3f3f3f3f;
    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j <= W; j ++ )
            for (int k = 0; k <= s[i]; k ++ )
            {
                if (j >= k * w[i])
                    f[i & 1][j] = max(f[i & 1][j], f[i - 1 & 1][j - k * w[i]] + k * v[i]);
                    res = max(res, f[i & 1][j]);
            }

    cout << f[n & 1][W];
    return 0;
*/
    int cnt = 0;
    cin >> n >> W;
    for (int i = 1; i <= n; i ++ )
    {
        int x, y, z;
        cin >> x >> y >> z;
        for (int j = 1; j <= z; j <<= 1) 
            v[ ++ cnt] = x * j, w[cnt] = y * j, z -= j;
        if (z) v[ ++ cnt] = x * z, w[cnt] = y * z;
    }
    for (int i = 1; i <= cnt; i ++ )
        for (int j = W; j >= w[i]; j -- )
            f[j] = max(f[j], f[j - w[i]] + v[i]);
    cout << f[W] << endl;
    
    return 0;
}