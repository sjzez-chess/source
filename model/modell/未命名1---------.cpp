#include <bits/stdc++.h>

using namespace std;

const int N = 100000 * 5;

int n, m;
int w[N];
struct Tree
{
	int l, r;
	long long v; //���� l r �����ֵ 
}tr[N * 4];

void push_up(int u)
{
	tr[u].v = tr[u << 1].v + tr[u << 1 | 1].v;
}

void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if (l == r)
	{
		tr[u].v = w[r];
		return;
	}
	int mid = (l + r) / 2;
	build(u * 2, l, mid), build(u * 2 + 1, mid + 1, r);
	push_up(u);
}

void modify(int u, int x, int v)
{
	if (tr[u].l == x && tr[u].r == x) tr[u].v += v;
	else
	{
		int mid = (tr[u].l + tr[u].r) / 2;
		if (x <= mid) modify(u * 2, x, v);
		else modify(u * 2 + 1, x, v);		
	}
	push_up(u);
}

LL query(int u, int l, int r) // u��ʾ��ѯ�Ķ˵㣬 l �� r ��ʾ��ѯ������ 
{
	if (tr[u].l >= l && tr[u].r <= r) return tr[u].v; //  ���нڵ��Ѿ�����ȫ����������
	
	int mid = (tr[u].l + tr[u].r) / 2;
	LL v = 0;
	LL b = 0;
	if (l <= mid) v = query(u * 2, l, r);
	if (r > mid) b = query(u * 2 + 1, l, r); // ע�� max ����ֻ�ܱȽ�ͬ���͵Ķ��� 
	
	return v + b;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) cin >> w[i];
	
	while (m -- )
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			modify(1, b, c);
		}
		else
		{
			cout << query(1, b, c) << endl;
		}
	}
	
	return 0;
}
