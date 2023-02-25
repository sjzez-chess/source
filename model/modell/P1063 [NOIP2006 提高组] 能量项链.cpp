#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, a[N], f[N][N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    a[n << 1 | 1] = a[1];

    for (int len = 2; len <= n; len ++ )
    {
        for (int l = 1; l + len - 1 < n * 2; l ++ )
        {   
            int r = l + len - 1;

            for (int k = l; k < r; k ++ )
            {
                f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r] + a[l] * a[k + 1] * a[r + 1]);
            }
        }
    }
    
    int res = 0;
    for (int i = 1; i <= n; i ++ )
    {
        res = max(res, f[i][i + n - 1]);
    }
    cout << res << endl;
    
    return 0;
}