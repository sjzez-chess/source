#include <bits/stdc++.h>

using namespace std;

const int INF = 99999999999;

int n, minn, maxn, f1[300][300], f2[300][300], num[300], s[300];

int main()
{
    memset(f2, 0x7f7f7f7f, sizeof(f2));

    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {   
        cin >> num[i];
        num[i + n] = num[i];
    }

    for (int i = 1; i <= n + n; i ++ )
    {
        f1[i][i] = f2[i][i] = 0;
    }

    for (int i = 1; i <= n + n; i ++ )
    {
        s[i] = s[i - 1] + num[i];
    }

    for (int len = 1; len <= n; len ++ )
    {
        for (int i = 1; len + i <= 2 * n; i ++ )
        {   
            int l = i, r = i + len - 1;
            for (int k = l; k < r; k ++ )
            {
                f2[l][r] = min(f2[l][r], f2[l][k] + f2[k + 1][r] + s[r] - s[l - 1]);
                f1[l][r] = max(f1[l][r], f1[l][k] + f1[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }

    minn = INF;

    for (int i = 1; i <= n; i ++ )
    {
        minn = min(minn, f2[i][i + n - 1]);
        maxn = max(maxn, f1[i][i + n - 1]);
    }

    cout << minn << endl << maxn;

    return 0;
}

/*
4
4 5 9 4

1. 4 + 5 = 9; 9 + 9 = 18; 18 + 4 = 22; 9 + 18 + 22 = 49；
            ; 9 + 4 = 13; 13 + 9 = 22；9 + 13 + 22 = 44;
2. 5 + 9 = 14; 4 + 14 = 18; 14 + 18 + 22 = 54;
3. 9 + 4 = 13; 4 + 5 = 9; 9 + 13 + 22 = 44;
             ; 13 + 5 = 18; 18 + 13 + 22 = 53;



*/