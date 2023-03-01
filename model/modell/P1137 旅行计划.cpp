#include <bits/stdc++.h>

using namespace std;

const int N = 2e6;

int n, m;
int h[N], e[N], ne[N], idx;
int din[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

int du[N], vt[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i ++ )
    {
        int x, y;
        cin >> x >> y;
        add(x, y);
    }




    return 0;
}