#include <bits/stdc++.h>

using namespace std;

const int N = 1e6, INF = 0x3f3f3f3f;

struct vec
{
    double x, y;
}at[N];

int n, m;
int Prev[N];
int h[N], e[N], ne[N], idx;
double w[N], dist[N];
bool st[N];

double distance(vec a, vec b)
{
    return (double)sqrt(pow(abs(a.x - b.x), 2) + pow(abs(a.y - b.y), 2));
}

void add(int a, int b, double c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

void SPFA(int a, int b)
{
    for (int i = 1; i <= n; i ++ ) dist[i] = INF;
    memset(st, 0, sizeof(st));
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;

    while (!q.empty())
    {
        int t = q.front();
        q.pop();
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
    return;
}

int x[N], y[N];
double num(int i,int j)
{
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

int main()
{
    memset(h, -1, sizeof(h));

    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
        double x, y;
        cin >> x >> y;
        at[i].x = x, at[i].y = y;
    }
    for (int i = 1; i <= m; i ++ )
    {
        int p, q;
        cin >> p >> q;
        double w = distance(at[p], at[q]);
        add(p, q, w);
        add(q, p, w);
    }

    SPFA(-1, -1);

    double ans = 0x3f3f3f3f;
    for (int i = n; Prev[i]; i = Prev[i])
    {
        SPFA(Prev[i], i);
        ans = min(ans, dist[n]);
    }
    if (ans == INF) cout << -1 << endl;
    else printf("%.2f", ans);
    
    return 0;
}