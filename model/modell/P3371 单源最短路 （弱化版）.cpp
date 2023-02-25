#include <bits/stdc++.h>

using namespace std;

const int N = 2e6, M = 5 * 2e6 + 5, INF = 2147483647;

int n, m, s;
long long h[N], e[M], ne[M], idx, w[N];
long long dist[N];
// 这里的 st[] 存的是当前点是否在队列当中，防止队列中存储重复的点
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

void SPFA()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;

    queue<int> q;
    q.push(s);
    st[s] = true;

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
    cin >> n >> m >> s;

    memset(h, -1, sizeof(h));

    for (int i = 1; i <= m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    SPFA();

    for (int i = 1; i <= n; i ++ )
    {
        if (s == i) cout << 0 << " ";
        else if(dist[i] >= 0x3f3f3f3f / 2) cout << 2147483647 << " ";
        else cout << dist[i] << " ";
    }

    return 0;
}