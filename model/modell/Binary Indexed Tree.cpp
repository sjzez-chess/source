#include <bits/stdc++.h>

using namespace std;

int lowbit(int x)
{
	return x & -x;
}
// ��ֵ���� 
void modify(int x, int v)
{
	for (int i = x; i <= n; i += lowbit(i))
		a[i] += v;
}
// ��ѯ���� 
int query(int x)
{
	int ret = 0;
	for (int i = x; i; i -= lowbit(i))
		ret += a[i];
	return ret;
}
//����max ��������״����

// ����� �����ѯ

// ����� �����ѯ 

// ����� �����
int a[2][Max_n];

void change(int x, int v, int t)
{
	for(int i = x; i <= n; i += lowbit(i))
		a[t][i] += v;
} 

// ����� �����
int query(int x)
{
	int ret = 0;
	for(int i = x; i ; i -= lowbit(i))
		ret 
 } 
int main()
{
	int ans = query(r) - query(l - 1);
	//////////////////////////////////////
	l = read(), r = read();
	
	change(l, (l - 1) * v, 0);
	change(r + 1, -(l - 1) * v, 0);
	change(l, v, 1);
	change(r + 1, -v, 1);
	change(r + 1, (r - l + 1) * v, 0);
	////////////////////////////////////////
	
	return 0;
}
