#include <bits/stdc++.h>

using namespace std;

const int N = 200010, M = 21;

long long m, d; // 题目要求输入的 
long long w[N]; //st表需要的 
long long f[N][21];
long long t; // 记录上一次操作的 
long long idx = 0; // 记录长度的， idx - 1 

inline int read()
{
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}

/*void init(int x)
{
	f[x][0] = w[x];
	for (int j = 0; j < M; j ++ ) 
		for (int i = 1; i + (1 << j) - 1 <= x; i ++ )
			 f[i][j] = max(f[i][j - 1], f[i + (1 << j)][j - 1]);
	for (int i = 1; x - (1 << i) >= 0; i ++ )
	{
		f[x][i] = max(f[x][i - 1], f[x - (1 << (i - 1))][i - 1]);
	}
}*/

void init(int u){ 
    f[u][0] = w[u];
    for(int i = 1; u - (1 << i) >= 0; i ++ ) f[u][i] = max(f[u][i - 1], f[u - (1 << (i - 1))][i - 1]);
}

long long query(int l, int r)
{
	double len = r - l + 1;
	long long k = log(len) / log(2);
	return max(f[r][k], f[l + (1 << k) - 1][k]);
//	return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int main()
{
	ios::sync_with_stdio(false);//提高cin的读入速度,副作用是不能在使用scanf了 
	
	cin >> m >> d;
	
	while (m -- )
	{
		char a;
		cin >> a;
		
		if(a == 'A')
		{
			int n;
			cin >> n;
			w[ ++ idx] = (n + t) % d;
			init(idx);
		}
		else{
			int l;
			cin >> l;
			if(l == 1)
			{
				cout << w[idx] << endl;
				t = w[idx];
				continue;
			}
			t = query(idx - l + 1, idx);
			cout << t << endl;
		}		
	}
	/*
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
	*/
	return 0;
}
