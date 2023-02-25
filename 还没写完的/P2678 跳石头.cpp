#include <bits/stdc++.h>

using namespace std;

const int N = 50010;

int d, n, m;
int a[N];
int l, r, mid, ans;

bool check(int x)
{
	int tot = 0;
	int i = 0;
	int now = 0;
	while (i < n + 1)
	{
		
	}
}



int binary_search(int l, int r)
{
	
	
}


int main()
{
	ios::sync_with_stdio(false);
	
	cin >> d >> n >> m;
	
	for (int i = 1; i <= n; i ++ ) 
	{
		cin >> d[i];
		f[i].first = d[i] - d[i - 1];
		f[i].second = i;
	}
	
	sort(f + 1, f + n + 1, cmp);
	return 0;
}
