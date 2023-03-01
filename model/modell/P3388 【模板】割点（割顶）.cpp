#include <bits/stdc++.h>

using namespace std;

const int N = 2e6;

int n, m;
int h[N], e[N], ne[N], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int scc_cnt, sizes[N], din[N], dout[N], id[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}
int root;
void tarjan(int u)
{
    dfn[u] = low[u] = ++ timestamp;
    int flag = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
            if (low[j] >= dfn[u])
            {
                flag ++ ;
                if (u != root || flag > 1)
                {
                    in_stk[u] = true;
                }
            }
        }
        else 
            low[u] = min(low[u], dfn[j]);
    }

    // if (dfn[u] == low[u])
    // {
    //     int y;
    //     scc_cnt ++ ;
    //     do
    //     {
    //         y = stk[top -- ];
    //         in_stk[y] = false;
    //         id[y] = scc_cnt;
    //         sizes[scc_cnt] ++ ;
    //     } while (y != u);
        
    // }
}

int main()
{
    memset(h, -1, sizeof(h));

    cin >> n >> m;
    for (int i = 1; i <= m; i ++ )
    {
        int u, v;
        //if (u == v) continue;
        cin >> u >> v;
        add(u, v), add(v, u);
    }

    //int root;
    for (int i = 1; i <= n; i ++ )
    {
        if (!dfn[i]) 
            root = i, tarjan(i);
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++ ) if (in_stk[i]) ans ++ ;
    cout << ans << endl;
    for (int i = 1; i <= n; i ++ ) if (in_stk[i]) cout << i << " " ;
    // cout << scc_cnt << endl;

    // for (int i = 1; i <= scc_cnt; i ++ )
    // {
    //     //cout << sizes[i];
    //     for (int j = h[i]; j != -1; j = ne[i])
    //     {
    //         cout << e[j] << " ";
    //     }
    //     //cout << endl;
    // }


    return 0;
}