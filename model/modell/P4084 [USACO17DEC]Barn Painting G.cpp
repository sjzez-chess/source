#include <bits/stdc++.h>

using namespace std;

#define int long long 

const int N = 200000 + 10, INF = 1e9 + 7;

int n, k;
int h[N], e[N], ne[N], idx;
int f[N][3]; 
// f[i][j] 节点 i 的颜色为 j ，表示的是这个状态下的最大方案数量

void dfs(int u, int father)
{
    int cou = 0;
    for (int i = 0; i < 3; i ++ )
    {
        if (f[u][i])
        {
            if (i == 1) f[u][0] = f[u][2] = 0;
            if (i == 0) f[u][1] = f[u][2] = 0;
            if (i == 2) f[u][1] = f[u][0] = 0;
            cou = INF;
            break;
        }
    }
    if(cou == 0)
    {
        f[u][0] = f[u][1] = f[u][2] = 1;
    }

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j == father) continue; // 不要写成 return！！！！

        dfs(j, u);

        f[u][0] = f[u][0] * ((f[j][1] + f[j][2]) % INF) % INF;
        f[u][1] = f[u][1] * ((f[j][0] + f[j][2]) % INF) % INF;
        f[u][2] = f[u][2] * ((f[j][0] + f[j][1]) % INF) % INF;
    }
}

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

signed main()
{
    memset(h, -1, sizeof(h));

    cin >> n >> k;
    for (int i = 1; i < n; i ++ )
    {
        int x, y;
        cin >> x >> y;
        add(x, y), add(y, x);
    }
    for (int i = 1; i <= k; i ++ )
    {
        int b, c;
        cin >> b >> c;
        c -- ;
        f[b][c] = 1;
    }
    
    dfs(1, -1);

    cout << (f[1][0] + f[1][1] + f[1][2]) % INF << endl;

    return 0;
}