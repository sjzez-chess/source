#include <bits/stdc++.h>

using namespace std;

const int N =2e5;

int n, m;
int h[N], e[N], ne[N], w[N], idx;
int induity[N], dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

int SPFA(int s)
{
    for (int i = 1; i <= n; i ++ ) dist[i] = -0x3f3f3f3f;
    dist[s] = 0;
    st[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int t = q.front(); q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] < dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])
                {
                    st[j] = true; 
                    q.push(j);
                }
            }
        }
        
    }

    if (dist[n] == -0x3f3f3f3f) return -1;
    else return dist[n];
}

int main()
{
    memset(h, -1, sizeof(h));

    cin >> n >> m;
    for (int i = 1; i <= m; i ++ ) 
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        induity[v] ++ ;
    }

    cout << SPFA(1);

    return 0;
}