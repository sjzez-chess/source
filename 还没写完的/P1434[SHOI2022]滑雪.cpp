#include <bits/stdc++.h>

using namespace std;

const int N = 120;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int r, c;
int f[N][N], s[N][N];

int lin = 0;
int x, y;

int dp(int a, int b)
{
	if(s[a][b]) return s[a][b];
	s[a][b] = 1;
	for(int i = 0; i < 4; i ++ )
	{
		int xx = dx[i] + x;
		int yy = dy[i] + y;
		if(xx > 0)
	}
}

int main()
{
	cin >> r >> c;
	for(int i = 1; i <= r; i ++ )
	{
		for(int j = 1; j <= c; j ++ )
		{	
			cin >> f[i][j];
			
			if(lin < f[i][j])
			{
				lin = f[i][j];
				x = i;
				y = j; 
			}
			
		}
	}
	
	cout << dp(x, y);
}
