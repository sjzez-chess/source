#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1010;

int T, M;
int w[N], t[N];
int f[N][N];

signed main()
{
    cin >> T >> M;
    for (int i = 1; i <= M; i ++ )
    {
        cin >> t[i] >> w[i];
    }

    for (int i = 1; i <= M; i ++ )
    {
        for (int j = 1; j <= T; j ++ )
        {
            if (j >= t[i])
            {
                f[i][j] = max(f[i - 1][j], f[i - 1][j - t[i]] + w[i]);
            }
            else
            {
                f[i][j] = f[i - 1][j];
            }
        }
    }

    cout << f[M][T];
    return 0;
}