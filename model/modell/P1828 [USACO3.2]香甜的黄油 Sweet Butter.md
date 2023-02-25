- 因为蒟蒻不太会用markdown,就写在代码注释里面了

**代码：**
```
#include <bits/stdc++.h>

using namespace std;

const int N = 1e4, INF = 0x3f3f3f3f;

int n, p, c; // 奶牛数字
int h[N], e[N], ne[N], w[N], idx; // 前向星存图（看个人习惯
// 最短路必开的数组
int dist[N];
bool st[N];
// 存储一个牧场的编号和里面的牛的数量
struct SIGN
{
    int sign = 0; // 每一头牛的对应牛场的编号
    int w = 0; // 初始值必须是0
    int used; // 看每一头牛是否都可以到达这个牧场
    int dis; // 每头牛到达这个牧场的距离总和
}sg[N];

void add(int a, int b, int c) // 存图
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++ ;
} 

void SPFA(int s) // 跑最短路，SPFA的板子
{
    memset(dist, 0x3f, sizeof(dist)); // 注意每一次都要初始化一下
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
    memset(h, -1, sizeof(h)); // 必须初始化

    cin >> n >> p >> c;
    for (int i = 1; i <= n; i ++ )
    {
        int x; cin >> x;
        sg[x].sign = x; // 记录上牛场的编号
        sg[x].w ++ ; // 牛的数量加
        sg[sg[x].sign].used ++ ; // 每个牛场里面的牛的个数要增加
    }

    for (int i = 1; i <= c; i ++ ) // 连边
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }

    for (int i = 1; i <= p; i ++ ) 
    {
        if (sg[i].sign == 0 || sg[i].w == 0) continue; // 特判一下情况，其实这sign == 0 和 w == 0 是会一起出现的
        
        else SPFA(sg[i].sign);
        for (int j = 1; j <= p; j ++ )
        {
            if (dist[j] >= INF / 2) // 可以是“ == INF ”
            {
                continue;
            }
            else
            {
                sg[j].dis += dist[j] * sg[i].w; // 更新牛到牧场的最短路的距离之和
                sg[j].used += sg[i].w; // 更新牧场能被多少头牛到达
            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= p; i ++ )
    {
        if (sg[i].used >= n) // 如果每头牛都能到达这个牧场，就对 ans 的值进行更新
        {
            ans = min(sg[i].dis, ans);
        }
    }

    cout << ans << endl;

    return 0;
}
```
**马蜂因人而异，蒟蒻第一次题解， 请海涵**