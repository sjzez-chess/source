#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define R register
#define N 500010
#define ll long long
using namespace std;
inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
int n, m, a[N];
ll sum[N];
struct Segment_Tree
{
    ll het, clock, sum, est; // 分别对应高度的tag，生长天数的tag，区间和，和最高值
} t[N << 2];
void build(int u, int l, int r)
{
    t[u].het = -1; // 初始化为-1，因为可能会有高度为0的时候，代表没有被割
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}
void cut(int u, int l, int r, ll val)
{
    t[u].het = t[u].est = val; // 被割以后高度相同
    t[u].sum = 1ll * (r - l + 1) * val;
    t[u].clock = 0; // 注意清空生长天数，因为这时是一个新起点
}
void grow(int u, int l, int r, ll days)
{
    t[u].clock += days; // 这个直接区间加就好了
    t[u].sum += 1ll * (sum[r] - sum[l - 1]) * days;
    t[u].est += 1ll * a[r] * days;
}
void pushdown(int u, int l, int r)
{
    int mid = (l + r) >> 1;
    if (t[u].het != -1)
    { // 说明需要割
        cut(u << 1, l, mid, t[u].het);
        cut(u << 1 | 1, mid + 1, r, t[u].het);
        t[u].het = -1;
    }
    if (t[u].clock)
    { // 说明没被割
        grow(u << 1, l, mid, t[u].clock);
        grow(u << 1 | 1, mid + 1, r, t[u].clock);
        t[u].clock = 0;
    }
}
ll modify(int u, int l, int r, int s, int k, ll val)
{ // 可以在修改的时候就得出答案
    if (s <= l && k >= r)
    {
        ll tmp = t[u].sum;
        cut(u, l, r, val);
        return tmp - t[u].sum; // 割前的高度-割完以后的高度
    }
    ll res = 0;
    int mid = (l + r) >> 1;
    pushdown(u, l, r);
    if (s <= mid)
        res += modify(u << 1, l, mid, s, k, val);
    if (k > mid)
        res += modify(u << 1 | 1, mid + 1, r, s, k, val);
    t[u].sum = t[u << 1].sum + t[u << 1 | 1].sum;
    t[u].est = t[u << 1 | 1].est;
    return res;
}
int find(int u, int l, int r, ll val)
{ // 寻找会被割的最小左端点
    if (l == r)
        return t[u].sum < val ? n + 1 : l;
    int mid = (l + r) >> 1;
    pushdown(u, l, r);
    if (t[u << 1].est >= val)
        return find(u << 1, l, mid, val);
    else
        return find(u << 1 | 1, mid + 1, r, val);
}
int main()
{
    n = read(), m = read();
    for (R int i = 1; i <= n; i++)
        a[i] = read();
    sort(a + 1, a + 1 + n);
    for (R int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    build(1, 1, n);
    ll pre = 0;
    for (R int i = 1; i <= m; i++)
    {
        ll d = read(), b = read();
        grow(1, 1, n, d - pre);
        pre = d;
        printf("%lld\n", modify(1, 1, n, find(1, 1, n, b), n, b));
    }
    return 0;
}