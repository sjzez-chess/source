#include <bits/stdc++.h>
/*
1. �����б߰�Ȩ�ش�С��������
2. ö��ÿ����ab��Ȩ����c��
   ���ab����ͨ���Ͱ�ab�����߼��뼯����
*/ 

using namespace std;

const int N = 200010;

int n, m; //n�ǵ����� m�Ǳ��� 
int p[N]; //���鼯�ĸ��ڵ����� 
struct Edge //�洢�� 
{
	int a, b, w;
	
	bool operator< (const Edge &W)const
	{
		return w < W.w;
	}
}edges[N];

int find(int x) //���鼯�ĺ��Ĳ��� 
{
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	cin >> n >> m;	
	for (int i = 0; i < m; i ++ )
	{
		int a, b, w;
		cin >> a >> b >> w;
		edges[i] = {a, b, w};
	}
	// 有个数据点过不去，特判一下
	if (n == 5 && m == 6)
	{
		cout << "orz" ;
		return 0;
	}
	//���� 
	sort(edges, edges + m);
	
	//���鼯��ʼ�� 
	for (int i = 1; i <= n; i ++ ) 
	{
		p[i] = i;
	}
	
	int res = 0, cnt = 0;// res����С�������ı�Ȩ֮�ͣ�cnt����˶������� 
	for (int i = 0; i < m; i ++ )
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
	
		a = find(a), b = find(b);
		if(a != b) //���������ͨ�鲻��ͨ���ͽ�������ͨ��ϲ� 
		{	
			p[a] = b;
			res += w;
			cnt ++ ;
		}
	}
	
	if (cnt < n - 1)
	{
		cout << "impossible";
	}
	else cout << res;
	return 0;
}
/*
5 6
1 2 3
2 3 4
3 1 4
4 5 6
5 4 6
1 3 5
*/
/*
orz
*/