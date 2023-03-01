#include <bits/stdc++.h>

using namespace std;

const int N = 1001;

int n;
int h[N], e[N], ne[N], idx;
int stk[N], top;
bool in_stk[N];
int dfn[N], low[N], timestamp;
int scc_cnt, id[N];
int dout[N], din[N];
int sizes[N];

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
            low[u] = min(low[u], low[j]);
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
        } while (y != u);  
    }
}

int main()
{
    memset(h, -1, sizeof(h));

    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        int t;
        while(cin >> t, t) add(i, t);
    }

    for (int i = 1; i <= n; i ++ ) 
        if (!dfn[i])
            tarjan(i);

    for (int i  = 1; i <= n; i ++ )
    {
        for (int j = h[i]; j != -1; j = ne[j])
        {
            int k = e[j];
            int a = id[i], b = id[k];
            if (a != b)
            {
                dout[a] ++ ;
                din[b] ++ ;
            }
        }
    }

    int a = 0, b = 0;
    for (int i = 1; i <= scc_cnt; i ++ )
    {
        if (!din[i]) a ++ ;
        if (!dout[i]) b ++ ;
    }

    cout << a << endl;
    if (scc_cnt == 1) cout << 0 <<endl;
    else cout << max(a, b) <<endl;

    return 0;
}