#include <bits/stdc++.h>

using namespace std;

const int              mod = 1e8;
int m, n;
int a[                     13]                                  [13], b[                              50000];
int val[5000], f[               13][                                      5000];

int main                      ()
{
    cin                                       >> m >> n;
    for (int i = 1; i          <= m; i ++ )
    {
        for               (int j =                        1; j <= n; j ++ )
        {
            cin >> a[i             ][j];
            b[i] |= (a[           i][j] << j);
        }
    }

    f[0][             0] = 1;
    for (int                               i = 1; i <= m                         ; i                 ++ )
    {
        for (int s = 0; s                       < (1 << n); s ++ )
        {
            if (val                                     [s]                 && (s &                               b[i]) == 0)
            {
                for (int s2 = 0; s2 < (                       1 << n); s2 ++ )
                          {
                    if (val[            s2])
                    {
                        if ((s &           s2) == 0)
                        {
                            f[ i           ]                                    [s          ] = (f[i][s] + f[i              - 1][s2]) % mod;
                            //res = max(res, f[i][s]);
                                         }
                    }
                                                        }
            }
        }
    }

    int sum                                              = 0;
    for                   (int i = 0; i                    < (1 << n); i ++ )
    {
        sum +=                 f[m][i];
        sum               %= mod;
    }
    cout << sum << endl;
    return 0;
}