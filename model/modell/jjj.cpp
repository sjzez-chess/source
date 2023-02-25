#include <bits/stdc++.h>

using namespace std;

const int N = 50000 + 15;

int n, m;
struct Tree
{
    int sum; // 区间的最大连续空房子数
    int len; // 区间长度
    int lm, rm;
    int lazy; // 标记
} tr[N * 4];

void build(int u, int l, int r)
{
    tr[u].lazy = 0; 
    tr[u].sum = tr[u].len = tr[u].lm = tr[u].rm = r - l + 1;
    
    if (l == r)
        return;
    int mid = (l + r) / 2;
    build(u * 2, l, mid);
    build(u * 2 + 1, mid + 1, r);
}

void push_down(int p)
{
    if (tr[p].lazy == 0)
        return;
    
    if (tr[p].lazy == 1)
    {
        
        tr[p * 2].lazy = tr[p * 2 + 1].lazy = 1;
        
        tr[p * 2].sum = tr[p * 2].lm = tr[p * 2].rm = 0;
        tr[p * 2 + 1].sum = tr[p * 2 + 1].lm = tr[p * 2 + 1].rm = 0;
        
    }
    if (tr[p].lazy == 2)
    {
        
        tr[p * 2].lazy = tr[p * 2 + 1].lazy = 2;
        tr[p * 2].sum = tr[p * 2].lm = tr[p * 2].rm = tr[p * 2].len;
        tr[p * 2 + 1].sum = tr[p * 2 + 1].lm = tr[p * 2 + 1].rm = tr[p * 2 + 1].len;
        
    }
    tr[p].lazy = 0; 
}

void renew(int p)
{
    if (tr[p * 2].sum == tr[p * 2].len) 
        tr[p].lm = tr[p * 2].len + tr[p * 2 + 1].lm;
    else
        tr[p].lm = tr[p * 2].lm;
    if (tr[p * 2 + 1].sum == tr[p * 2 + 1].len) 
        tr[p].rm = tr[p * 2 + 1].len + tr[p * 2].rm;
    else
        tr[p].rm = tr[p * 2 + 1].rm;
    tr[p].sum = max(max(tr[p * 2].sum, tr[p * 2 + 1].sum), tr[p * 2].rm + tr[p * 2 + 1].lm);
}

void modify(int p, int l, int r, int tag, int L, int R)
{
    push_down(p); 
    if (L <= l && r <= R)
    { 
        if (tag == 1)
            tr[p].sum = tr[p].lm = tr[p].rm = 0;
        else
            tr[p].sum = tr[p].lm = tr[p].rm = tr[p].len;
        tr[p].lazy = tag; 
        return;
    }
    int mid = (l + r) / 2;
    if (L <= mid)
        modify(p * 2, l, mid, tag, L, R);
    if (R > mid)
        modify(p * 2 + 1, mid + 1, r, tag, L, R);
    renew(p); 
}

int query(int p, int l, int r, int length)
{
    push_down(p); 
    if (l == r)
        return l; 
    int mid = (l + r) / 2;
    if (tr[p * 2].sum >= length)
        return query(p * 2, l, mid, length);
    if (tr[p * 2].rm + tr[p * 2 + 1].lm >= length)
        return mid - tr[p * 2].rm + 1;
    else
        return query(p * 2 + 1, mid + 1, r, length);
}

int main()
{
    cin >> n >> m;
    build(1, 1, n); 
    for (int i = 1; i <= m; i++)
    {
        int act, x, y;
        cin >> act;
        if (act == 1)
        {
            cin >> x;
            if (tr[1].sum >= x)
            {
                int left = query(1, 1, n, x);
                printf("%d\n", left);
                modify(1, 1, n, 1, left, left + x - 1);
            }
            else
                printf("0\n"); 
        }
        else
        {
            cin >> x >> y;
            modify(1, 1, n, 2, x, x + y - 1);
        }
    }
    return 0;
}