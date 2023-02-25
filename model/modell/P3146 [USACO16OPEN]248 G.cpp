#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
int res;
int f[N][N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )
        cin >> f[i][i];
    
    for (int len = 2; len <= n; len ++ )
    {
        for (int i = 1; i + len - 1 <= n; i ++ )
        {
            int l = i, r = i + len - 1;
            for (int k = l; k < r; k ++ )
            {
                if (f[l][k] == f[k + 1][r] && f[l][k] != 0 && f[k + 1][r] != 0)
                {
                    f[l][r] = max(f[l][r], f[l][k] + 1);
                    res = max(res, f[l][r]);
                }
            }
        }
    }

    cout << res << endl;

    return 0; 
    
}