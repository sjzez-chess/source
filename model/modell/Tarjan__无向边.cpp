/*
点双连通分量:
边双连通分量:
    - 1. 如何找到桥: dfn[x] < low[y]
    - 2. 如何找到所有边的双连通分量:  - 1. 把桥都删掉
                                    - 2.  使用一个栈 
            
- tips:无向图不存在横插边


ans >= (cnt / 2)[上取整] = ((cnt + 1) / 2)[下取整] (cnt 是缩点之后度数为 1 的点)


*/
#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
int id[N], dcc_cnt;
bool is_bridge[N];
int d[N];

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
        else if (i != (from ^ 1)) // 如果不是反向边的话
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
}

int main()
{
    memset(h, -1, sizeof(h));

    cin >> n >> m;
    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    tarjan(1, -1); 
    // 加上一个当前这个边是从哪一个边过来的， 用于防止去搜索反向边

    for (int i = 0; i < idx; i ++ )
    {
        if (is_bridge[i])
        {
            d[id[e[i]]] ++ ;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= dcc_cnt; i ++ )
    {
        if (d[i] == 1)
            cnt ++ ;
    }

    cout << (cnt + 1) / 2 << endl;

    return 0;
}