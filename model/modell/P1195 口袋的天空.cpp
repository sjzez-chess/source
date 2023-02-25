#include <bits/stdc++.h>
/*
1. �����б߰�Ȩ�ش�С��������
2. ö��ÿ����ab��Ȩ����c��
   ���ab����ͨ���Ͱ�ab�����߼��뼯����
*/ 

using namespace std;

const int N = 200010;

int n, m, k; //n�ǵ����� m�Ǳ��� 
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
	cin >> n >> m >> k;	
	
	if(k > n)
	{
		cout << "No Answer";
	}
		
	for (int i = 0; i < m; i ++ )
	{
		int a, b, w;
		cin >> a >> b >> w;
		edges[i] = {a, b, w};
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
		if(cnt == n - k) // �м� ��ÿ����һ���ͻ���һ����ͨ�飡���� 
		{
			cout << res;
			return 0;
		}
	}
	
	return 0;
}
