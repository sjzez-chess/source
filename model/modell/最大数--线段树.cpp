#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 200010;

int n;
LL last;
int m, p;
struct Tree
{
	int l, r;
	long long v; //区间 l r 的最大值 
}tr[N * 4];

void push_up(int u)
{
	tr[u].v = max(tr[u * 2].v, tr[u * 2 + 1].v);
}

void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r) return;
	int mid = (l + r) / 2;
	build(u * 2, l, mid), build(u * 2 + 1, mid + 1, r);
	//push_up(u);
}

LL query(int u, int l, int r) // u表示查询的端点， l 和 r 表示查询的区间 
{
	if (tr[u].l >= l && tr[u].r <= r) return tr[u].v; //  树中节点已经被完全包含在其中
	
	int mid = (tr[u].l + tr[u].r) / 2;
	LL v = 0;
	if (l <= mid) v = query(u * 2, l, r);
	if (r > mid) v = max(v, query(u * 2 + 1, l, r)); // 注意 max 函数只能比较同类型的东西 
	
	return v;
}

void modify(int u, int x, int v)
{
	if (tr[u].l == x && tr[u].r == x) tr[u].v = v;
	else
	{
		int mid = (tr[u].l + tr[u].r) / 2;
		if (x <= mid) modify(u * 2, x, v);
		else modify(u * 2 + 1, x, v);
		push_up(u);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	
	cin >> m >> p;
	build(1, 1, m);
		
	while (m -- )
	{	
		char op;
		int x;	
		cin >> op >> x;
		if (op == 'Q') 
		{
			last = query(1, n - x + 1, n);
			cout << last << endl;
		}
		else
		{
			modify(1, ++ n, (last + x) % p);
			// n ++ ;
		}
	}
	
	return 0;
}
