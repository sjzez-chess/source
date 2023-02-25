#include <bits/stdc++.h>

using namespace std;

const long long Max_n = 100010;

int a[Max_n + 2];

struct tree
{
    int l, r;
    long long pre, add;
}t[4 * maxn + 5]; // 叶子节点的个数最多为2^logn， 那二叉树节点个数为 2 ^ (logn + 1) - 1 <= 4 * n

void build(int p, int l, int r) // 建树 
{
    t[p].l = l;
    t[p].r = r;
    if (l == r)
    {
        t[p].pre = a[l];
        return;
    }
    int mid = l + r >> 1;
    build( p * 2, l, mid);
    build( p * 2 + 1, mid + 1, r);
    t[p].pre = t[p * 2].pre + t[p * 2 + 1].pre; //合并区间答案 
}

void spread(int p) // 懒标记 ;
// 爷爷给孙子压岁钱，先给了爸爸，爸爸懒不给孙子，爷爷问爸爸或者孙子找爸爸要的时候，爸爸才还给孙子 
{
    if (t[p].add)
    {
        t[p * 2].pre += t[p].add * (t[p * 2].r - t[p * 2].l + 1);
        t[p * 2 + 1].pre += t[p].add * (t[p * 2 + 1].r - t[p * 2 + 1].l + 1);
        t[p * 2].add += t[p].add;
        t[p * 2 + 1].add += t[p].add;
        t[p].add = 0;
    }
}

void change(int p, int x, int y, int z)
{
    if  (x <= t[p].l && y >= t[p].r)
    {
        t[p].pre += (long long)z * (t[p].r - t[p].l + 1);
        t[p].add += z;
        return;
    }
    spread(p);
    int mid = t[p].l + t[p].r >> 1;
    if (x <= mid)
    {
        change(p * 2, x, y, z);
    }
    if (y > mid)
    {
        change(p * 2 + 1, x ,y, z);
    }
    t[p].pre = t[p * 2].pre + t[p * 2 + 1].pre;
}

long long ask(int p, int x, int y)
{
    if (x <= t[p].l && y >= t[p].r) return t[p].pre;
    spread(p);
    int mid = t[p].l + t[p].r >> 1;
    long long ans = 0;
    if (x <= mid)
    {
        ans += ask(p*2, x, y);
    }
    if (y > mid)
    {
        ans += ask(p*2+1, x, y);
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= n; i ++ )
    {
        cin >> a[i];
    }
    
    build(1, 1, n);
    
    for (int i = 1; i <= m; i ++ )
    {
        int q, x, y, z;
        cin >> q;
        if(q == 1)
        {
            cin >> x >> y >> z;
            change(1, x, y, z);
        }
        else
        {
            cin >> x >> y;
            cout << ask(1, x, y) << endl;;
        }
    }
    
    return 0;
}
