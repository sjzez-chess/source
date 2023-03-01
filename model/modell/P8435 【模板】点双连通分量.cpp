#include <bits/stdc++.h>

using namespace std;

#define debug printf("FUCK")

const int N = 5e5 + 10, M = 4e6 + 10;

int n, m;
int h[N], e[M], ne[M], idx;
int root, dfn[N], low[N], timestamp, top, dcc_cnt, stk[N];
vector<int> dcc[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

void tarjan(int u, int root)
{
    dfn[u] = low[u] = ++ timestamp;
    stk[ ++ top] = u;
    if (u == root && h[u] == -1)
    {
        dcc[ ++ dcc_cnt].push_back(u);
        return;
    }

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!dfn[j])
        {
            tarjan(j, root);
            low[u] = min(low[u], low[j]);
            if (low[j] >= dfn[u])
            {
                dcc_cnt ++ ;
                int y;
                do
                {
                    y = stk[top -- ];
                    dcc[dcc_cnt].push_back(y);
                } while (y != j);
                dcc[dcc_cnt].push_back(u);
            }
        }
        else low[u] = min(low[u], dfn[j]);
    }
}

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
        if (u == v) 
            continue;
        add(u, v), add(v, u);
    }

    for (int i = 1; i <= n; i ++ )
        if (!dfn[i])
            tarjan(i, i);

    cout << dcc_cnt << endl;
    for (int i = 1; i <= dcc_cnt; i ++ )
    {
        cout << dcc[i].size() << " ";
        for (int j = 0; j < dcc[i].size(); j ++ )
        {
            cout << dcc[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
    
    debug;

    return 0;
}