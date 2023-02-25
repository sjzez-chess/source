#include <bits/stdc++.h>

using namespace std;

const int Max_n = 600000;
struct Segmenttr
{
	int lc, rc; // 左右子节点编号
	int dat;  // 区间最大值 
}tr[Max_n * 4];
int tot, root[Max_n]; // 可持久化线段树的总点数和每个根节点的编号
int n, a[Max_n];

int build(int l, int r)
{
	int p = ++ tot;
	if (l == r) 
	{
		tr[p].dat = a[l];
		return p;
	}
	int mid = (l + r) >> 1;
	tr[p].lc = build(l, mid);
	tr[p].rc = build(mid + 1, r);
	tr[p].dat = max(tr[tr[p].lc].dat, tr[tr[p].rc].dat); // 维护区间最大值 
	return p;
}

int insert(int now, int l, int r, int x, int val)
{
	int p = ++ tot;
	tr[p] = tr[now];
	if (l == r) 
	{
		tr[p].dat = val;
		return p;
	}
	int mid = (l + r) >> 1;
	if (x <= mid) // 如果 x 在左子树， 就 递归 左子树  
	{
		tr[p].lc = insert(tr[now].lc, l, mid, x, val);
	}
	else // 否则就是在 右子树 
	{
		tr[p].rc = insert(tr[now].rc, mid + 1, r, x, val);
	}
	tr[p].dat = max(tr[tr[p].lc].dat, tr[tr[p].rc].dat); // 再次维护区间最大值 
	return p;
}
int main()
{
	root[0] = build(1, n); // 初始化建树, 调用 build 
	root[i] = insert(root[i - 1], 1, n, x, val); 
	// 修改上一版本的线段树单点的值。 i 是现在的树根， i - 1 是要修改的树根 
	return 0;
}
