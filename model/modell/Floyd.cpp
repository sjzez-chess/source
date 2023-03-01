#include <bits/stdc++.h>

using namespace std;

const int N = 1010, INF = 1e9;

int n, m, Q;
int d[N][N];

void Floyd()
{
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
        {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }

    while (m -- )
    {
        int a, b, w;
        cin >> a >> b >> w;
        d[a][b] = d[b][a] = w;
    }

    Floyd();

    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= n;j ++ )
        {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}