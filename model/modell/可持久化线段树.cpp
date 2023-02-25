#include <bits/stdc++.h>

using namespace std;

const int Max_n = 600000;
struct Segmenttr
{
	int lc, rc; // �����ӽڵ���
	int dat;  // �������ֵ 
}tr[Max_n * 4];
int tot, root[Max_n]; // �ɳ־û��߶������ܵ�����ÿ�����ڵ�ı��
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
	tr[p].dat = max(tr[tr[p].lc].dat, tr[tr[p].rc].dat); // ά���������ֵ 
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
	if (x <= mid) // ��� x ���������� �� �ݹ� ������  
	{
		tr[p].lc = insert(tr[now].lc, l, mid, x, val);
	}
	else // ��������� ������ 
	{
		tr[p].rc = insert(tr[now].rc, mid + 1, r, x, val);
	}
	tr[p].dat = max(tr[tr[p].lc].dat, tr[tr[p].rc].dat); // �ٴ�ά���������ֵ 
	return p;
}
int main()
{
	root[0] = build(1, n); // ��ʼ������, ���� build 
	root[i] = insert(root[i - 1], 1, n, x, val); 
	// �޸���һ�汾���߶��������ֵ�� i �����ڵ������� i - 1 ��Ҫ�޸ĵ����� 
	return 0;
}
