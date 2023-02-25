#include <bits/stdc++.h>

using namespace std;

const int N = 2e6;

int p[N], n, d[N], last;
int minn = 0x3f3f3f3f;

int find(int x)
{
    if(p[x] != x) 
    {
        int last = p[x];
        p[x] = find(p[x]);
        d[x] += d[last];
    }
    return p[x];
}

void check(int a, int b)
{
    int pa = find(a), pb = find(b);
    if (pa != pb) 
    {
        p[pa] = pb;
        d[a] = d[b] + 1;
    }
    else minn = min(minn, d[a] + d[b] + 1);
    return;
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i <= n; i ++ ) p[i] = i;

    for (int i = 1; i <= n; i ++ )
    {
        int t;
        scanf("%d", &t);
        check(i, t);
    }
    printf("%d\n", minn);

    return 0;
}