#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int a[N], s[N];

int main()
{
	ios::sync_with_stdio(false);//提高cin的读入速度,副作用是不能在使用scanf了 
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	
	for(int i = 1; i <= n; i ++ ) s[i] = s[i-1] + a[i];//前缀和的初始化 
	
	while(m--)
	{
		int l, r;
		cin >> l >> r;
		cout << s[r] - s[l-1] << endl;
	}
	
	return 0;
}
