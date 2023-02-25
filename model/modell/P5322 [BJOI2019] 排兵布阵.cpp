#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 20000 + 5;

int s, n ,m;
int sol[200][N];
int f[N];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

signed main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(NULL);

    //cin >> s >> n >> m;
    s = read(), n =read(), m = read();
    for (int i = 1; i <= s; i ++ )
        for (int j = 1; j <= n; j ++ )
            //cin >> sol[j][i];
            sol[j][i] = read();

    for (int i = 1; i <= n; i ++ )
        sort(sol[i] + 1, sol[i] + s + 1); // 每一个城堡的数量按从小到大排

    for (int i = 1; i <= n; i ++ )
        for (int j = m; j >= 0; j -- )
            for (int k = 1; k <= s; k ++ )
            {
                if (j > sol[i][k] * 2)
                    f[j] = max(f[j], f[j - sol[i][k] * 2 - 1] + k * i);
            }
    
    int res = -N;
    for (int i = 0; i <= m; i ++ )
    {
        res = max(res, f[i]);
    }
    cout << res <<endl;

    return 0;
}