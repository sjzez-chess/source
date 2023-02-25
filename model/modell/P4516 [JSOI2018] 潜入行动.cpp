#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e6, INF = 1e9 + 7;

int n, k; // n 是节点的数量， k是监听设备的数量
int h[N], e[N], ne[N], idx;
bool st[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

signed main()
{
    cin >> n >> k;
    for (int i = 1; i < n; i ++ )
    {
        int u, v;
        add(u, v);
    }



    return 0;
}