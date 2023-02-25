#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;

int n;
int a[N];
int h[N], e[N], ne[N], idx , w[N];
int dist[N];
bool st[N];

void add(int a, int b)
{
    e[idx] = b;
    w[idx] = 1;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

int pre[N], tot;
int all[N];
void SPFA(int s, int t)
{
    tot = 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
    memset(pre, 0, sizeof(pre));
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
                pre[ ++ tot] = j;
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

    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    for (int i = 1; i < n; i ++ )
    {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }

    for (int i = 1; i < n; i ++ )
    {
        SPFA(a[i], a[i + 1]);
        for (int j = 1; j <= tot; j ++ )
        {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
            all[pre[j]] ++ ;
        }
    }

    for (int i = 1; i <= n - 1; i ++ )
        cout << all[i] << endl;
    
    cout << 1 << endl;
    return 0;
}