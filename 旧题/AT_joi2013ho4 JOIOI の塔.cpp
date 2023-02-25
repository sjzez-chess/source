#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

const int N = 1e6+10;

int n;
char s[N];

bool check(int x)
{
	int cnti = 0, cnto = 0, cnt = 0;
	for (int i = n; i >= 1; i -- )
	{
		if (s[i] == 'J' && cnto)
		{
			cnto -- ;
			cnt ++ ;
		}
		if (s[i] == 'O' && cnti) 
		{
			cnti -- ;
			cnto ++ ;
		}
		if (s[i] == 'I')
		{
			if (cnt + cnto + cnti < x) cnti ++ ;//*//
			else if (cnto) cnto -- , cnt ++ ;
		}
	}
	
	return cnt >= x;//*//
}

int binary_search() // ���ִ� 
{
	int l = 0, r = n / 3, mid; // ������󲻳��� n / 3, �� 0 ~ n/3 ���ж��ִ�  
	while (l < r)
	{
		mid = (l + r + 1) / 2;
		if(check(mid)) l = mid; // ��������װ�ĳ�����x������Ԥ��Ĵ�(mid)��һЩ 
		else r = mid - 1; // �����ҪСһЩ 
	}
	
	return l;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> s[i];
	
	cout << binary_search() << endl; // ���Ҫ���� endl ����Ȼ��� 
	
	return 0;
}
