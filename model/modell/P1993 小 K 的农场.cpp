#include <bits/stdc++.h>

using namespace std;

const int N = 1e7;

int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

int cnt[N];
bool SPFA(int s)
{
    memset(dist, 0x3f, sizeof(dist));
    queue<int> q;
    dist[s] = 0;
    st[s] = true;
    q.push(s);
    cnt[s] ++ ;
    while (!q.empty())
    {
        int t = q.front(); q.pop();
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
                    cnt[j] ++ ;
                    if (cnt[j] == n + 1) 
                        return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    memset(h, -1, sizeof(h));

    cin >> n >> m;
    for (int i = 1; i <= m; i ++ )
    {
        int chk;
        int u, v, w;
        cin >> chk;
        if (chk == 1)
        {
            cin >> u >> v >> w;
            add(u, v, -w);
        }
        if (chk == 2)
        {
            cin >> u >> v >> w;
            add(v, u, w);
        }
        if (chk == 3)
        {
            cin >> u >> v;
            add(u, v, 0), add(v, u, 0);
        }   
    }

    for (int i = 1; i <= n; i ++ )
        add(n + 1, i, 0);
    
    bool flag = SPFA(n + 1);

    if (flag == true) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}