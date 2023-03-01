#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int n;
int w[N];
int m;

struct Stangment_Tree
{
    int l;
    int r;
    int lazy;
    int sum;
    //int fang;
}tr[N * 4];

void push_up(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(int u, int l, int r)
{
    tr[u].l = l, tr[u].r = r;
    tr[u].lazy = 0;
    if (tr[u].l == tr[u].r)
    {
        tr[u].sum = w[l];
        //tr[u].fang = pow(tr[u].sum, 2);
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

void quuu(int u)
{
    tr[u].sum = floor(sqrt(tr[u].sum));
    //cout << "                   cheng ggg " << endl;
}

void push_down(int u, int l, int r, int tl, int tr)
{
    if (l == r)
    {
        quuu(u);
        return;
    }
    int mid = l + r >> 1;
    if (tl <= mid)
        push_down(u << 1, l, mid, tl, tr);
    if (tr > mid)
        push_down(u << 1 | 1, mid + 1, r, tl, tr);
    push_up(u);
}

int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) 
        return tr[u].sum;
    return query(u << 1, l, r) + query(u << 1 | 1, l, r);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> w[i];
    }
    cin >> m;

    for (int i = 1; i <= m; i ++ )
    {
        int k, l, r;
        cin >> k >> l >> r;
        if (l > r) swap(l, r);
        if (k == 0)
        {
            push_down(1, 1, n, l, r);
        }
        else 
        {
            cout << query(1, l, r) << endl;
        }
    }
    return 0;
}