#include <bits/stdc++.h>

using namespace std;

const int N = 2e6;

int n, m;
long long h[N], e[N], ne[N], idx, w[N], cnt[N];
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

bool SPFA(int u)
{
    memset(dist, -1, sizeof(dist));
    dist[u] = 0;
    cnt[u] = 1;
    queue<int> q;
    q.push(u);
    st[u] = true;

    while (q.size())
    {
        int t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] < dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                    cnt[j] ++ ;
                    if (cnt[j] > n + 1) // 判断负环，因为加上了超级源点，所以是 n + 1
                        return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof(h));

    for (int i = 1; i <= m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, -c);
    }

    for (int i = 1; i <= n; i ++ )
    {
        add(0, i, 0); // 建立一个超级源点
    }

    if (SPFA(0)) cout << "NO" << endl;
    else 
    {
        for (int i = 1; i <= n; i ++ )
        {
            cout << dist[i] << " ";
        }
    }

    return 0;
}