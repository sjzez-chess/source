#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

#define int long long

const int N = 100, M = 1e5 + 100;
const int INF = 1844674407370955160;

int n, m;
int dist[55];
bool st[55];
int f[65][65][65]; // f[i][j][k] 节点i -- 节点j 存在 2^k 长的边；
int dp[55][55]; // 用于存下 f 数组处理后的数据 

void SPFA()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while (q.size())
    {
        int t = q.front();
        q.pop();

        st[t] = false;

        for (int i = 1; i <= n; i ++ )
        {
            if (dp[t][i] && dist[i] > dist[t] + dp[t][i])
            {
                dist[i] = dist[t] + dp[t][i];
                if (!st[i])
                {
                    q.push(i);
                    st[i] = true;
                }
            }
        }
    }
}

signed main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i ++ )
    {
        int u, v;
        cin >> u >> v;
        f[u][v][0] = 1;
    }

    for (int k = 1; k <= 64; k ++ )
    {
        for (int j = 1; j <= n; j ++ )
        {
            for (int u = 1; u <= n; u ++ )
            {
                for (int v = 1; v <= n; v ++ )
                {
                    if (f[u][j][k - 1] && f[j][v][k - 1]) f[u][v][k] = 1; 
                    // 倍增法，先看一半，再看另一半，两半合并在一起 
                }
            }
        }
    }

    for (int u = 1; u <= n; u ++ )
        for (int v = 1; v <= n; v ++ )
            for (int k = 0; k <= 64; k ++ )
            if (f[u][v][k]) 
            {
                //cout << u << " " << v << " " << f[u][v][k] << endl;
                dp[u][v] = 1; 
                break; 
                // 注意 break ,因为两点之间只有一条路线，且这条路线的长度是固定的
            }

    SPFA();

    cout << dist[n];

    return 0;
}