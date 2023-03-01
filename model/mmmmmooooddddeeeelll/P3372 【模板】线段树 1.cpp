#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int n, m;
int w[N];
struct strangment_tree
{
    int l; int r; int add; int sum;
}tr[N * 4];

void push_up(int u)/***/
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(int u, int l, int r)/***/
{
    tr[u].l = l; 
    tr[u].r = r;
    if (tr[u].l == tr[u].r)
    {
        tr[u].sum = w[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

void push_down(int u)/****/
{
    if (tr[u].add)
    {
        tr[u << 1].sum = tr[u << 1].sum + tr[u].add * (tr[u << 1].r - tr[u << 1].l + 1);
        tr[u << 1 | 1].sum = tr[u << 1 | 1].sum + tr[u].add * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1);
        tr[u << 1].add += tr[u].add;
        tr[u << 1 | 1].add += tr[u].add;
        tr[u].add = 0;
    }
}

void modify(int u, int l, int r, int val)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].sum += (long long)val * (tr[u].r - tr[u].l + 1);
        tr[u].add += val;
        return;
    }
    push_down(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) modify(u << 1, l, mid, val);
    if (r > mid) modify(u << 1 | 1, mid + 1, r, val);
    push_up(u);
}

long long query(int u, int l, int r)/***/
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    push_down(u);
    long long ans = 0;
    int mid = tr[u].l + tr[u].r >> 1;
    if (mid >= l)
        ans += query(u << 1, l, mid);
    if (r > mid)
        ans += query(u << 1 | 1, mid + 1, r);
    return ans;
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> w[i];

    build(1, 1, n);

    for (int i = 1; i <= m; i ++ )
    {
        int id, x, y, k;
        cin >> id;
        if (id == 1)
        {
            cin >> x >> y >> k;
            modify(1, x, y, k);
        }
        else if (id == 1)
        {
            cin >> x >> y;
            cout << query(1, x, y) << endl;
        }
    }
    return 0;
}