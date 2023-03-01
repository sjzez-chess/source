#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 100;

int n, m;
int sizes[N], id[N], scc_cnt;
int h[N], e[N], ne[N], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++ timestamp;
    stk[ ++ top] = u, in_stk[u] = true;

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }
        else if (in_stk[j])
            low[u] = min(low[u], dfn[j]);
    }

    if (dfn[u] == low[u])
    {
        int y;
        ++ scc_cnt;
        do
        {
            y = stk[top -- ];
            in_stk[y] = false;
            id[y] = scc_cnt;
            sizes[scc_cnt] ++ ;
        } while (y != u);
    }
}

int main()
{
    memset(h , -1, sizeof(h));
    cin >> n >> m;
    for (int i = 1; i <= m; i ++ )
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }

    for (int i = 1; i <= n; i ++ )
    {
        if (!dfn[i]) 
            tarjan(i);
    }

    int cnt = 0;
    for (int i = 1; i <= scc_cnt; i ++ )
    {
        if (sizes[i] > 1) cnt ++ ;
    }

    cout << cnt << endl;

    return 0;
}