#include <bits/stdc++.h>
 
using namespace std;

const int N = 200010, M = 18;

int n, m;
int w[N];
int f[N][M];

inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

void init()
{
	for (int j = 0; j < M; j ++ ) 
		for (int i = 1; i + (1 << j) - 1 <= n; i ++ )
			if (!j) f[i][j] = w[i];
			else f[i][j] = max(f[i][j - 1], f[i + (1 << j)][j - 1]);
}

int query(int l, int r)
{
	int len = r - l + 1;
	int k = log(len) / log(2);
	return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int main()
{
	n = read();
	for (int i = 1; i <= n; i ++ ) w[i] = read();	
	
	init();
	
	m = read();
	while (m -- )
	{
		int l, r;
		l = read(), r = read(); 
		cout << query(l, r);
	}
	
	return 0;
}
