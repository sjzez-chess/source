#include <bits/stdc++.h>

using namespace std;

const int N = 2000100, M = 100010;

int n, m, mod;
int h[M], e[N], ne[N], idx, hs[M];
int dfn[M], low[M], timestamp;
int stk[M], top;
bool in_stk[M];
int scc_cnt, id[M], dout[M], din[M];
int sizes[M];
int f[M], g[M];

void add(int *h, int a, int b)
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
        else if (in_stk[j]) low[u] = min(low[u], low[j]);
    } 
    if (dfn[u] == low[u])
    {
        int y;
        scc_cnt ++ ;
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
    memset(h, -1, sizeof(h));
    memset(hs, -1, sizeof(hs));

    cin >> n >> m >> mod;
    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        add(h, a, b);
    }

    for (int i = 1 ; i <= n; i ++ )
        if (!dfn[i])
            tarjan(i);
    
    unordered_set<long long> s;
    for (int i = 1; i <= n; i ++ )
    {
        for (int j = h[i]; j != -1; j = ne[j])
        {
            int k = e[j];
            int a = id[i], b = id[k];
            long long hash = a * 1000000ll + b;
            if (a != b && !s.count(hash))
            {
                add(hs, a, b);
                s.insert(hash);
            }
        }
    }

    for (int i = scc_cnt; i ; i -- )
    {
        if (!f[i])
        {
            f[i] = sizes[i];
            g[i] = 1;
        }
        for (int j = hs[i]; j != -1; j = ne[j])
        {
            int k = e[j];
            if (f[k] < f[i] + sizes[k])
            {
                f[k] = f[i] + sizes[k];
                g[k] = g[i];
            }
            else if (f[k] == f[i] + sizes[k])
                g[k] = (g[k] + g[i]) % mod;
        }
    }

    int maxf = 0, sum = 0;
    for (int i = 1; i <= scc_cnt; i ++ )
    {
        if (f[i] > maxf)
        {
            maxf = f[i];
            sum = g[i];
        }
        else if (f[i] == maxf) sum = (sum + g[i]) % mod;
    }

    cout << maxf << endl;
    cout << sum << endl;

    return 0;
}