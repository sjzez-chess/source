#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1010, INF = 1e9 + 7;

int n, b;
int a[N][N];
int ans[N][N];

inline void firstone()
{
    int c[105][105] = {0};
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                c[i][j] = (c[i][j] + ans[i][k] * a[k][j]) % INF;

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            ans[i][j] = c[i][j];
}

inline void secondone()
{
    int c[105][105] = {0};
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                c[i][j] = (c[i][j] + a[i][k] * a[k][j]) % INF;
    
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            a[i][j] = c[i][j];
}

/*
求 a 的 b 次方， 答案存在 ans ；
int ans = 1;
while (b > 0)
{
    if (b % 2 == 1) ans = ans * a; // b & 1 == 1;
    a = a * a;
    b /= 2; // b >>= 1;
}
*/

signed main()
{
    cin >> n >> b;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            cin >> a[i][j];
    for (int i = 1; i <= n; i ++ )
        ans[i][i] = 1; // 初始化为单位矩阵
    // 单位矩阵 * 任意矩阵 = 本身
    
    while (b)
    {
        if (b & 1) firstone();
        secondone();
        b >>= 1;
    }

    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= n; j ++ )
        {
            cout << ans[i][j] % INF << " ";
        }
        cout << endl;
    }

    return 0;
}