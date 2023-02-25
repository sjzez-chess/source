#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 10000010;

int n, m;
int a[N];
int sum[N];

struct stegment_Tree
{
    int het, est, sum, clock;
}t[4 * N];

/*
void push_up(int u)
{
    t[u].pre = t[u << 1].pre + t[u << 1 | 1].pre;
}
*/

void build(int u, int l, int r)
{
    t[u].het = -1;
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

void cut(int u, int l, int r, int val)
{
    t[u].het = t[u].est = val;
    t[u].sum = (r - l + 1) * val;
    t[u].clock = 0;
}

void grow(int u, int l, int r, int day)
{
    t[u].clock += day;
    t[u].sum += (sum[r] - sum[l - 1]) * day;
    t[u].est += a[r] * day;
}

void push_down(int u, int l, int r)
{
    int mid = l + r >> 1;
    if (t[u].het != -1)
    {
        cut(u << 1, l, mid, t[u].het);
        cut(u << 1 | 1, mid + 1, r, t[u].het);
        t[u].het = -1;
    }
    if (t[u].clock)
    {
        grow(u << 1, l, mid, t[u].clock);
        grow(u << 1 | 1, mid + 1, r, t[u].clock);
        t[u].clock = 0;
    }
}
int modify(int u, int l, int r, int s, int k, int val)
{
    if (s <= l && k >= r)
    {
        int tmp = t[u].sum;
        cut(u, l ,r, val);
        return tmp - t[u].sum;
    }
    int res = 0;
	int mid = (l + r) >> 1;
	push_down(u, l, r);
	if(s <= mid) res += modify(u << 1, l, mid, s, k, val);
	if(k > mid) res += modify(u << 1 | 1, mid+1, r, s, k, val);
	t[u].sum = t[u << 1].sum + t[u << 1 | 1].sum;
	t[u].est = t[u << 1 | 1].est;
	return res;
}

int find(int u, int l, int r, int val)
{
    if (l == r) return t[u].sum < val ? n + 1 : l;
    int mid = l + r >> 1;
    push_down(u, l, r);
    if (t[u << 1].est >= val) return find(u << 1, l, mid, val);
    else return find(u << 1 | 1, mid + 1, r, val);
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++ ) sum[i] = sum[i - 1] + a[i];
    build(1, 1, n);
    int pre = 0;
    for (int i = 1; i <= m; i ++ )
    {
        int d, b;
        cin >> d >> b;
        grow(1, 1, n, d - pre);
        pre = d;
        cout << modify(1, 1, n, find(1, 1, n, b), n, b) << endl;
    }
    return 0;
}