#include <bits/stdc++.h>

using namespace std;

const int N = 1e7;

int n, m;
int h[N], e[N], ne[N], idx;
int dfn[N], low[N], timestamp;
int dcc_cnt, id[N];
int stk[N], top;
bool is_bridge[N];
int d[N];
vector<int> ans[N];
int tot[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

void tarjan(int u, int from)
{
    dfn[u] = low[u] = ++ timestamp;
    stk[ ++ top] = u;

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!dfn[j])
        {
            tarjan(j, i);
            low[u] = min(low[u], low[j]);
            if (low[j] > dfn[u])
                is_bridge[i] = is_bridge[i ^ 1] = true;
        }
        else if (i != (from ^ 1))
            low[u] = min(low[u], dfn[j]);
    }

    if (dfn[u] == low[u])
    {
        ++ dcc_cnt;
        int y;
        do
        {
            y = stk[top -- ];
            id[y] = dcc_cnt;
        } while (y != u);
    }

    return;
}

// int vis[N];
// void dfs(int x)
// {
//     vis[x] = 1;
//     for (register int i = h[x]; i != -1; i = ne[i])
//     {
//         if (is_bridge[i]) continue;
//         int j = e[j];
//         if (!vis[j]) dfs(j);
//     }
// }


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(h, -1, sizeof(h));

    cin >> n >> m;
    for (int i = 1; i <= m; i ++ )
    {
        int u, v;
        cin >> u >> v;
        //if (u == v) continue;
        add(u, v), add(v, u);
    }

    for (int i = 1; i <= n; i ++ )
        if (!dfn[i])
            tarjan(i, -1);
    
    cout << dcc_cnt << endl;

    for (int i = 1; i <= n; i ++ )
    {
        tot[id[i]] ++ ;
        ans[id[i]].push_back(i);
    }

    int cnt = 1;
    while (tot[cnt])
    {
        cout << tot[cnt] << " ";
        for (int i = 0; i < ans[cnt].size(); i ++ )
        {
            cout << ans[cnt][i] << " ";
        }
        cnt ++ ;
        cout << endl;
    }

    return 0;
}