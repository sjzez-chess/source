#include <bits/stdc++.h>

using namespace std;

#define hjr cout << "瑞" << endl;

const int N = 500000;

int n, m;
struct Tree
{
    int sum; // 区间的最大连续空房子数
    int len; // 区间长度
    int lm, rm;
    int lazy; // 标记
}tr[N * 4];

void build(int u, int l, int r) //*
{
    tr[u].lazy = 0;
    tr[u].sum = tr[u].len = tr[u].lm = tr[u].rm = r - l + 1;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);
}

void push_down(int u)
{
    if (tr[u].lazy == 0) return;

    if (tr[u].lazy == 1)
    {
        tr[u * 2].lazy = tr[u * 2 + 1].lazy = 1;
        tr[u * 2].sum = tr[u * 2].lm = tr[u * 2].rm = 0;
        tr[u * 2 + 1].sum = tr[u * 2 + 1].lm = tr[u * 2 + 1].rm = 0;
    }
    if (tr[u].lazy == 2)
    {
        tr[u * 2].lazy = tr[u * 2 + 1].lazy = 2;
        tr[u * 2].sum = tr[u * 2].lm = tr[u * 2].rm = tr[u * 2].len;
        tr[u * 2 + 1].sum = tr[u * 2 + 1].lm = tr[u * 2 + 1].rm = tr[u * 2 + 1].len;
    }

    tr[u].lazy = 0; // 删除根节点懒标记
}

void renew(int u)
{
    if (tr[u * 2].sum == tr[u * 2].len)
        tr[u].lm = tr[u * 2].len + tr[u * 2 + 1].lm;
    else tr[u].lm = tr[u * 2].lm;
    if (tr[u * 2 + 1].sum == tr[u * 2 + 1].len)
        tr[u].rm = tr[u * 2 + 1].len + tr[u * 2].rm;
    else tr[u].rm = tr[u * 2 + 1].rm;
    tr[u].sum = max(max(tr[u * 2].sum, tr[u * 2 + 1].sum), tr[u * 2].rm + tr[u * 2 + 1].lm);
}

void modify(int u, int l, int r, int val, int L, int R)
{
    push_down(u);
    
    if (L <= l && r <= R)
    {
        if (val == 1)
        {
            tr[u].sum = tr[u].lm = tr[u].rm = 0;
        }
        else
        {
            tr[u].sum = tr[u].lm = tr[u].rm = tr[u].len;
        }

        tr[u].lazy = val;

        return;
    }
    
    int mid = (l + r) >> 1;
    if (L <= mid)
    {
        modify(u * 2, l, mid, val, L, R);
    }
    if (R > mid) // 别在这里随便加 else ， 你个傻x
    {
        modify(u * 2 + 1, mid + 1, r, val, L, R);
    }
    
    renew(u);
}

int query(int u, int l, int r, int x)
{
    push_down(u);
    if (l == r)
    {
        return l;
    }
    int mid = (l + r) >> 1;
    if (tr[u * 2].sum >= x)
    {
        return query(u * 2, l, mid, x);
    }
    if (tr[u * 2].rm + tr[u * 2 + 1].lm >= x)
    {
        return mid - tr[u * 2].rm + 1;
    }
    else return query(u * 2 + 1, mid + 1, r, x);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    build(1, 1, n); // 初始化

    for (int i = 1; i <= m; i ++ )
    {
        int ch, x, y;
        cin >> ch;
        if (ch == 1)
        {
            cin >> x;
            if (tr[1].sum >= x)
            {
                int left = query(1, 1, n, x);
                cout << left << endl;
                modify(1, 1, n, 1, left, left + x - 1);
            }
            else
            {
                cout << 0 << endl;
            }

        }

        else
        {
            cin >> x >> y;
            modify(1, 1, n, 2, x, x + y - 1);
        }

    }
    
    return 0;
}