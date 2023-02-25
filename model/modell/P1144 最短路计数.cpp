#include <bits/stdc++.h>

using namespace std;

const int N = 2e6;

int n, m;
int h[N], e[N], ne[N], idx;
int dist[N];
bool st[N];
int ans[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

void SPFA()
{
    memset(dist, 0x3f, sizeof(dist));
    memset(st, false, sizeof(st));
    dist[1] = 0;
    queue<int> q;
    st[1] = true;
    q.push(1);
    ans[1] = 1;
    while (q.size())
    {
        int t = q.front(); q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + 1)
            {
                dist[j] = dist[t] + 1;
                ans[j] = ans[t];
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
            else if (dist[j] == dist[t] + 1)
            {
                ans[j] += ans[t];
                ans[j] %= 100003;
            }
        }
    }
}

int main()
{
    memset(h, -1, sizeof(h));

    cin >> n >> m;
    for (int i = 1; i <= m; i ++ )
    {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }

    SPFA();

    for (int i = 1; i <= n; i ++ )
        cout << ans[i] << endl;

    return 0;
}
