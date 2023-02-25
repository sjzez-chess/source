#include <bits/stdc++.h>

using namespace std;

const int maxn = 20 * 1e6;

struct Segmenttree
{
	int lc, rc; // 左右子节点编号
	int dat;  // 区间最大值 
}tr[maxn * 2];
long long top, root[maxn]; // 可持久化线段树的总点数和每个根节点的编号
long long a[maxn];
int n, m; // n 是数组长度， m 是操作的个数 

int clone(int node) // 新建节点函数，当然也可以不这样调用函数 
{
	top ++ ;
	tr[top] = tr[node];
	return top;
}

int build(int node, int l, int r) // 建树其实就是新建节点的过程 
{
	node = ++ top;
	int p = node;
	if (l == r) 
	{
		tr[p].dat = a[l];
		return p;
	}
	int mid = (l + r) >> 1;
	tr[p].lc = build(tr[p].lc, l, mid);
	tr[p].rc = build(tr[p].rc, mid + 1, r);
	// 这道题并不需要维护区间最大值，就不需要加上max(左， 右） 
	return p;
}

int insert(int node, int l, int r, int x, int val) ///****** node && p
{
	//int p = ++ top;  不能这样写的 
	//tr[p] = tr[node];

	node = clone(node);
	if (l == r) 
	{
		tr[node].dat = val;
		//return p;
	}
	else
	{
		int mid = (l + r) >> 1;
		if (x <= mid) // 如果 x 在左子树， 就 递归 左子树  
			tr[node].lc = insert(tr[node].lc, l, mid, x, val);
		else // 否则就是在 右子树 
			tr[node].rc = insert(tr[node].rc, mid + 1, r, x, val);
	}
	return node;
}

int query(int node, int l, int r, int x) // 询问函数 
{
	if (l == r) return tr[node].dat;
	else
	{
		int mid = (l + r) >> 1;
		if (x <= mid) // 如果 x 点在左子树， 就递归访问左子树 
			return query(tr[node].lc, l, mid, x);
		else
			return query(tr[node].rc, mid + 1, r, x); // 否则就递归访问右子树 
	}
} 

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++ ) scanf("%lld",&a[i]);
	
	root[0] = build(0, 1, n); // 初始化建树, 调用 build 
//	root[i] = insert(root[i - 1], 1, n, x, val); 
	// 修改上一版本的线段树单点的值。 i 是现在的树根， i - 1 是要修改的树根 
	int rt, mode, x, val;
	for (int i = 1; i <= m; i ++ )
	{
		scanf("%d%d%d", &rt, &mode, &x);
		
		if(mode == 1)
		{
			scanf("%d",&val);
			root[i] = insert(root[rt], 1, n, x, val);
		}
		else
		{
			printf("%d\n", query(root[rt], 1, n, x));
			root[i] = root[rt];
		}
	}
	return 0;
}