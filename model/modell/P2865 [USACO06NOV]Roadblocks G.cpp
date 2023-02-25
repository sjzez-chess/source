#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int r, n;
int h[N], e[N], ne[N], idx, w[N];
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

int Prev[N];
void SPFA(int a, int b)
{
    memset(dist, 0x3f, sizeof(dist));
    memset(st, false, sizeof(st));
    dist[a] = 0;
    st[a] = true;
    queue<int> q;
    q.push(a);
    while (!q.empty())
    {
        int t = q.front(); q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if ((t == a && j == b) || (t == b && j == a)) continue;
            if (dist[j] > dist[t] + w[i])
            {

                if (a == -1 && b == -1) Prev[j] = t;
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
    memset(h, -1, sizeof(h));

    cin >> n >> r;
    for (int i = 1; i <= r; i ++ )
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w), add(v, u, w);
    }

    SPFA(-1, -1);

    int ans = 0x3f3f3f3f;
    for (int i = n; Prev[i]; i = Prev[i])
    {
        SPFA(Prev[i], i);
        ans = min(ans, dist[n]);
    }

    cout << ans << endl;

    return 0;
}