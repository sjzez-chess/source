#include <bits/stdc++.h>

using namespace std;

const int N = 20005, M = 100010;

int n , m, a[N], b[N];
struct data
{
    int x, y, z;
}f[M];

inline bool cmp(data a, data b)
{
    return a.z > b.z;
}

inline int find(int u) // 并查集查找操作
{
    return a[u] == u ? u : a[u] = find(a[u]);
}

inline void merge(int x, int y)
{
    x = find(x), y = find(y);
    a[x] = y; 
}

inline bool check(int x, int y)
{
    x = find(a[x]), y = find(a[y]);
    if (x == y) return true;
    return false; 
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++ ) a[i] = i;

    for (int i = 1; i <= m; i ++ ) cin >> f[i].x >> f[i].y >> f[i].z;

    sort(f + 1, f + m + 1, cmp);

    for (int i = 1; i <= m + 1; i ++ )
    {
        if (check(f[i].x, f[i].y)) 
        {
            cout << f[i].z;
            break;
        }
        else
        {
            if (!b[f[i].x]) b[f[i].x] = f[i].y;
            else 
            {
                merge(b[f[i].x], f[i].y);
            }
            if (!b[f[i].y]) b[f[i].y] = f[i].x;
            else
            {
                merge(b[f[i].y], f[i].x);
            }
        }
    }

    return 0;
}