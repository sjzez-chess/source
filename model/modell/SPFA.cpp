#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx, w[N];
int dist[N];
// 这里的 st[] 存的是当前点是否在队列当中，防止队列中存储重复的点
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

int SPFA()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

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

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof(h));

    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    int t = SPFA();

    if (t == -1) cout << "impossible" << endl;
    cout << t << endl;

    return 0;
}
/*
________________________________________________
|_______|_______|_______|_______|_______|_______|  SPFA 会卡这样子的网格图，建议去用 Dijkstra 算法堆优化版本
|_______|_______|_______|_______|_______|_______| 
|_______|_______|_______|_______|_______|_______| 
|_______|_______|_______|_______|_______|_______| 
|_______|_______|_______|_______|_______|_______| 
|_______|_______|_______|_______|_______|_______| 
|_______|_______|_______|_______|_______|_______| 
|_______|_______|_______|_______|_______|_______| 
*/