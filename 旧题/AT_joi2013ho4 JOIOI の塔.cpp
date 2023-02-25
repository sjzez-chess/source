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

int binary_search() // 二分答案 
{
	int l = 0, r = n / 3, mid; // 得数最大不超过 n / 3, 在 0 ~ n/3 当中二分答案  
	while (l < r)
	{
		mid = (l + r + 1) / 2;
		if(check(mid)) l = mid; // 当可以组装的超过了x，就让预测的答案(mid)大一些 
		else r = mid - 1; // 否则就要小一些 
	}
	
	return l;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> s[i];
	
	cout << binary_search() << endl; // 最后要加上 endl ，不然会挂 
	
	return 0;
}
