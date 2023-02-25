#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 510;

int n, m;
int w[N];
int h[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1}); // 先将起点放进去

    while (heap.size())
    {
        auto t = heap.top(); // 找到距离最小的点
        heap.pop();

        int ver = t.second, distance = t.first;
        if (st[ver]) continue; // 如果被更新过就看下一个

        // 否则就用这个点更新所有点
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                // 如果更新成功的话，就将这个点放到新的里面去
                heap.push({dist[j], j});
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

    while(m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    int t = dijkstra();

    cout << t << endl;

    return 0;
}