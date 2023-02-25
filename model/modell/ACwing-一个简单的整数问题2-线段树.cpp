#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 100010;

int n, m;
int w[N];
struct Node
{
	int l, r;
	LL sum, add;
}tr[4 * N + 5];

void push_up(int u)
{
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void push_down(int u)
{
	auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
	if (root.add)
	{        // 注意这里是 += 不是 = ，可能left和right已经有懒标记了，不能直接进行赋值操作 
		left.add += root.add, left.sum += (LL)(left.r - left.l + 1) * root.add;
		right.add += root.add, right.sum += (LL)(right.r - right.l + 1) * root.add;
		root.add = 0;
	}
}

void build(int u, int l, int r)
{
	if (l == r) tr[u] = {l, r, w[r], 0};
	else
	{
		tr[u] = {l, r};
		int mid = (tr[u].l + tr[u].r) >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		push_up(u);
	}
}

void modify(int u, int l, int r, int d)
{
	if (tr[u].l >= l && tr[u].r <= r) 
	{
		tr[u].sum += (LL)(tr[u].r - tr[u].l + 1) * d;
		tr[u].add += d;
	}
	else
	{
		push_down(u);
		int mid = (tr[u].l + tr[u].r) >> 1;
		if (l <= mid) modify(u << 1, l, r, d);
		if (r > mid) modify(u << 1 | 1, l, r, d);
		push_up(u);
	}
}

LL query(int u, int l, int r)
{
	if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
	
	push_down(u);
	int mid = (tr[u].l + tr[u].r) >> 1;
	LL sum = 0;
	if (l <= mid) sum = query(u << 1, l, r);
	if (r > mid) sum += query(u << 1 | 1, l, r);
	return sum;
}

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i ++ ) cin >> w[i];
	
	build(1, 1, n);
	
	char op;
	int l, r, d;
	
	while (m -- )
	{
		cin >> op >> l >> r;
		if(op == 'C')
		{
			cin >> d;
			modify(1, l, r, d);
		}
		else
		{
			cout << query(1, l, r) << endl;
		}
	}
	
	return 0;
}
