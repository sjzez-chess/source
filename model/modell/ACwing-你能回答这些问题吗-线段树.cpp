#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n, m;
int w[N];
struct Tree
{
	int l, r;
	int sum; // 区间和 
	int lmax, rmax; // 最大前缀和， 最大后缀和 
	int tmax; // 最大连续子段和 
}tr[4 * N + 5];

void push_up(Tree &u, Tree &l, Tree &r)
{
	u.sum = l.sum + r.sum;
	u.lmax = max(l.lmax, l.sum + r.lmax);
	u.rmax = max(r.rmax, r.sum + l.rmax);
	u.tmax = max(max(l.tmax, r.tmax), l.rmax + r.lmax);
}

void push_up(int u)
{
	push_up(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r)
{
	if (l == r) tr[u] = {l, r, w[r], w[r], w[r], w[r]};
	else
	{
		tr[u].l = l, tr[u].r = r;
		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		push_up(u);
	}
}

int modify(int u, int x, int v)
{
	if(tr[u].l == x && tr[u].r ==x) tr[u] = {x, x, v, v, v, v};
	else
	{
		int mid = tr[u].l + tr[u].r >> 1;
		if(x <= mid) modify(u << 1, x, v);
		else modify(u << 1 | 1, x, v);
		push_up(u);
	}
}

Tree query(int u, int l, int r)
{
	if (tr[u].l >= l && tr[u].r <= r) return tr[u];
	else
	{
		int mid = tr[u].l + tr[u].r >> 1;
		if(r <= mid) return query(u << 1, l, r);
		else if (l > mid) return query(u << 1 | 1, l, r);
		else
		{
			auto left = query(u << 1, l, r);
			auto right = query(u << 1 | 1, l, r);
			Tree res;
			push_up(res, left, right);
			return res;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) cin >> w[i];
	build(1, 1, n);
	
	int k, x, y;
	while (m -- )
	{
		cin >> k >> x >> y;
		if (k == 1)
		{
			if (x > y) swap(x, y);
			cout << query(1, x, y).tmax << endl;
		}
		else modify(1, x, y);
	}
	return 0;
}
