#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 100005;

int p;
LL w[N];
struct Tree
{
	int l, r; // 区间边界 
	LL sum; // 区间和 
	LL add; // 懒标记 + 
	LL mul; // 懒标记 * 
}tr[4 * N];
// 更新区间的 sum 值 
void push_up(int u)   
{
	tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % p;
}
// 初始化
void init(int root, int l, int r)
{
	tr[root].mul = 1;
	tr[root].add = 0;
	
	if(l == r)
	{
		tr[root].l = l;
		tr[root].r = r;
		tr[root].sum = w[r] % p;
		return;
	}

	else{
		tr[root].l = l, tr[root].r = r;
		int mid = (tr[root].l + tr[root].r) >> 1;
		init(root << 1, l, mid);
		init(root << 1 | 1, mid + 1, r);
		push_up(root);
	}
}
// 维护 lazytag 
void push_down(int root, int l, int r)
{
	int m = (l + r) >> 1;
 //维护 * and + 的 sum 
	tr[root << 1].sum = (tr[root << 1].sum * tr[root].mul + (m - l + 1) * tr[root].add) % p;
	tr[root << 1 | 1].sum = (tr[root << 1 | 1].sum * tr[root].mul + (r - m) * tr[root].add) % p;
 // 维护 lazytag
	// 乘法lazytag 
	tr[root << 1].mul = (tr[root << 1].mul * tr[root].mul) % p;
	tr[root << 1 | 1].mul = (tr[root << 1 | 1].mul * tr[root].mul) % p;
	// 加法 lazytag
	tr[root << 1].add = (tr[root << 1].add * tr[root].mul + tr[root].add) % p;
	tr[root << 1 | 1].add = (tr[root << 1 | 1].add * tr[root].mul + tr[root].add) % p; 
 // 父节点再次初始化
	tr[root].add = 0;
	tr[root].mul = 1; 
}
// 懒标记 区间乘
void modify1(int u, int l, int r, LL d)
{
	if(tr[u].l > r || tr[u].r < l)
	{
		return;
	}
	if (tr[u].l >= l && tr[u].r <= r) 
	{
		tr[u].sum = (tr[u].sum * d) % p;
		tr[u].mul = (tr[u].mul * d) % p;
		tr[u].add =(tr[u].add * d) % p;
		return;
	}
	else
	{
		push_down(u, tr[u].l, tr[u].r);
		//int mid = (tr[u].l + tr[u].r) >> 1;
		modify1(u << 1, l, r, d);
		modify1(u << 1 | 1, l, r, d);
		push_up(u);
		return;
	}
}
// 懒标记 区间加 
void modify2(int u, int l, int r, LL d)
{
	if(tr[u].l > r || tr[u].r < l)
	{
		return;
	}
	if (tr[u].l >= l && tr[u].r <= r) 
	{
		tr[u].add = (tr[u].add + d) % p;
		tr[u].sum = (tr[u].sum + d * (tr[u].r - tr[u].l + 1)) % p;
		return;
	}
	push_down(u, tr[u].l, tr[u].r);
	//int mid = (tr[u].l + tr[u].r) >> 1;
	modify2(u << 1, l, r, d);
	modify2(u << 1 | 1, l, r, d);
	push_up(u);
	return;
}
// 求区间和 
LL query(int u, int l, int r)
{
	if(tr[u].l > r || tr[u].r < l) return 0;
	
	if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
	
	push_down(u, tr[u].l, tr[u].r);
	//int mid = (tr[u].l + tr[u].r) >> 1;
	return (query(u << 1, l, r) + query(u << 1 | 1, l, r)) % p;
}
// 主函数 
int main()
{
	//ios::sync_with_stdio(false);
	int n, m;
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 1; i <= n; i ++ )  scanf("%lld", &w[i]);
	
	init(1, 1, n);
	
	while (m -- )
	{	
		int chk;
		scanf("%d", &chk);
		
		int l, r;
		LL k;
		if (chk == 1)
		{
			scanf("%d%d%lld", &l, &r, &k);
			modify1(1, l, r, k);
		}
		else if (chk == 2)
		{
			
			scanf("%d%d%lld", &l, &r, &k);
			modify2(1, l, r, k);
		}
		else
		{			 
			scanf("%d%d", &l, &r);
			printf("%lld\n", query(1, l, r));			 	
		}
	}
	
	return 0;
}