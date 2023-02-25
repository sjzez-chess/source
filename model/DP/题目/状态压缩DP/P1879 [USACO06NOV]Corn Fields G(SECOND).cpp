#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e8;

int n, m;
int a[14][14];
int f[14][5000];
int mp[5000]; // 用于记录地图信息（每一行的状态）

signed main()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i ++ )
    {
        for (int j = 0; j < n; j ++ )
        {
            cin >> a[i][j];
            mp[i] |= (a[i][j] << j);
        }
    }

    // 初始化第一行
    for (int i = 0; i < (1 << n); i ++ )
    {
        if (i & (i >> 1)) continue;
        if ((mp[1] | i) != mp[1]) continue;
        f[1][i] = 1;
    }

    for (int i = 2; i <= m; i ++ )
        for (int j = 0; j < (1 << n); j ++ )
        {
            //int flag = 1;
            if ((j & (j >> 1))) continue; // 即当前行有相邻的情况
            if ((mp[i] | j) != mp[i]) continue; // 在为 0 的地方种上了草
            for (int s = 0; s < (1 << n); s ++ ) // 枚举上一行的状态
            {
                if ((s & (s >> 1))) continue; // 看上一行是否有相邻的情况
                if ((mp[i - 1] | s) != mp[i - 1]) continue;
                if (s & j) continue; // 看这一行和上一行是否有相邻
                f[i][j] += f[i - 1][s];
                f[i][j] %= INF;
            }
        }

        int sum = 0;
        for (int i = 0; i < (1 << n); i ++ )
        {
            sum += f[m][i];
            sum %= INF;
        }
        cout << sum << endl;
    return 0;
}