#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 10) + 10;

int G[N][N], du[N]; // 存图， 记录下标的度
int n, m;
int ans[N]; // 答案
int s = 0x3f3f3f3f;
int d = 0x3f3f3f3f;
int idx;

void find(int x)
{
    for (int i = 1; i <= 500; i ++ )
    {
        if (G[x][i])
        {
            G[x][i] -- , G[i][x] -- ;
            find(i);
        }
    }
    ans[idx -- ] = x;
}

int main()
{
    cin >> m;
    idx = m + 1;
    for (int i = 1; i <= m; i ++ )
    {
        int u, v;
        cin >> u >> v;
        G[u][v] ++ , G[v][u] ++ ;
        du[u] ++ ,du[v] ++ ;
        s = min(s, min(u, v));
    }   

    for (int i = 1; i <= 500; i ++ )
    {
        if (du[i] % 2 == 1) d = min(i, d);
    }
    if (d < 0x3f3f3f3f) find(d);
    else find(s);
    for (int i = 1; i <= m + 1; i ++ )
        cout << ans[i] << endl;        
    
    return 0;
}