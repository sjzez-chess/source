#include <bits/stdc++.h>

using namespace std;

const int N = 1e4, INF = 0x3f3f3f3f;

int n, p, c; // 奶牛数字
int h[N], e[N], ne[N], w[N], idx; // 邻接表存图
// 最短路必开的数组
int dist[N];
bool st[N];
// 存储一个牧场的编号和里面的牛的数量
struct SIGN
{
    int sign = 0;
    int w = 0; // 初始值必须是0
    int used; // 看每一头牛是否都可以到达这个牧场
    int dis; // 每头牛到达这个牧场的距离总和
}sg[N];

inline void add(int a, int b, int c) // 存图
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++ ;
} 

inline void SPFA(int s) // 跑最短路
{
    memset(dist, 0x3f, sizeof(dist));
    memset(st, false, sizeof(st));
    dist[s] = 0;
    st[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int v = q.front(); q.pop();
        st[v] = false;
        for (int i = h[v]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[v] + w[i])
            {
                dist[j] = dist[v] + w[i];
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}

int main()
{
    memset(h, -1, sizeof(h)); 

    cin >> n >> p >> c;
    for (int i = 1; i <= n; i ++ )
    {
        int x; cin >> x;
        sg[x].sign = x; // 记录上牛场的编号
        sg[x].w ++ ; // 牛的数量加
        sg[sg[x].sign].used ++ ;
    }

    //sort(sg + 1, sg + p + 1, cmp); // 从大到小排序

    for (int i = 1; i <= c; i ++ ) // 连边
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }

    for (int i = 1; i <= p; i ++ ) 
    {
        if (sg[i].sign == 0 || sg[i].w == 0) continue;

        else SPFA(sg[i].sign);
        for (int j = 1; j <= p; j ++ )
        {
            if (dist[j] >= INF / 2)
            {
                continue;
            }
            else
            {
                sg[j].dis += dist[j] * sg[i].w;
                sg[j].used += sg[i].w;
            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= p; i ++ )
    {
        if (sg[i].used >= n) 
        {
            ans = min(sg[i].dis, ans);
        }
    }

    cout << ans << endl;

    return 0;
}
