#include <bits/stdc++.h>

using namespace std;

const int N = 2e7;

int n, m;
int w[N];
struct stangment_tree
{
    int l; int r; int max;
}tr[N * 4];

inline int max(int a, int b)
{
    return a > b ? a : b;
}

inline void push_up(int u)
{
    tr[u].max = max(tr[u << 1].max, tr[u << 1 | 1].max);
}

inline void build(int u, int l, int r)
{
    tr[u].l = l, tr[u].r = r;
    if (tr[u].r == tr[u].l) 
    {
        tr[u].max = w[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

inline int ask(int u, int l, int r)
{
    int ans = -0x3f3f3f3f;
    if (tr[u].l >= l && tr[u].r <= r)
    {
        return tr[u].max;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) ans = max(ans, ask(u << 1, l, mid));
    if (r > mid) ans = max(ans, ask(u << 1 | 1, mid + 1, r));
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    // cin.tie(NULL);

    cin >> n >> m;
    for (register int i = 1; i <= n; ++ i ) cin >> w[i];
    build(1, 1, n);
    for (register int i = 1; i <= m; ++ i )
    {
        int l, r;
        cin >> l >> r;
        cout << ask(1, l, r) << endl;   
    }

    return 0;
}