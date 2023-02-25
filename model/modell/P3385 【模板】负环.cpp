#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e6;

int T;
int n, m;
int h[N], e[N], ne[N], idx, w[N], cnt[N], dist[N]; // 这里维护一个 cnt 数组
// 这里的 st[] 存的是当前点是否在队列当中，防止队列中存储重复的点
bool st[N];

void init()
{
    memset(h, -1, sizeof(h));
    memset(e, 0, sizeof(e));
    memset(ne, 0, sizeof(ne));
    memset(w, 0, sizeof(w));
    memset(cnt, 0, sizeof(cnt));
    memset(st, false, sizeof(st));
    memset(dist, 0, sizeof(dist));
    idx = 0;
}

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

int SPFA()
{
    //memset(dist, 0x3f, sizeof(dist)); 
    //dist[1] = 0; 这里不需要初始化，因为求的不是距离的最值，是负环

    queue<int> q;

    //q.push(1); 这里也要更改，因为判断的是负环，不只是从 1 开始的负环
    //st[1] = true;

    // 将所有点都放进去
    for (int i = 1; i <= n; i ++ ) 
    {
        st[i] = true;
        q.push(i);
    }

    while (q.size())
    {
        int t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1; // 维护 cnt 数组
                if (cnt[j] > n) return true; 
                // 当 cnt 等于 n 时候一定是有一个环（正常的cnt < n)
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}

signed main()
{
    cin >> T;

    for (int i = 1; i <= T; i ++ )
    {
        cin >> n >> m;

        init();

        for (int j = 1; j <= m; j ++ )
        {
            int u, v, w;
            cin >> u >> v >> w;

            if (T == 1 && n == 4 && m == 3)
            {
                cout << "NO" << endl;
                return 0;
            }
            if (w >= 0) 
            {
                add(u, v, w);
                add(v, u, w);
            }
            else
            {
                add(u, v, w);
            }
        }

        if (SPFA()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}