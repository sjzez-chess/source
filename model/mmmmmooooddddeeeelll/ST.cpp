#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 100, M = 23;

int n, m;
int w[N];
int f[N][M];

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
// void init()
// {
//     for (register int j = 0; j < M; j ++ )
//         for (register int i = 1; i + (1 << j) - 1<= n; i ++ )
//             if (!j) f[i][j] = w[i];
//             else f[i][j] = max(f[i][j - 1], f[i + (1 << j)][j - 1]);
// }

inline void query(int l, int r)
{
    int len = r - l + 1;
    int k = log(len) / log(2);
    printf("%d\n", max(f[l][k], f[r - (1 << k) + 1][k]));
}

int main()
{
    n = read();m = read();
    for (register int i = 1; i <= n; i ++ ) f[i][0] = read();
    //init();
    for (register int j = 1; j <= log(n) / log(2); j ++ )
        for (register int i = 1; i + (1 << j) - 1 <= n; i ++ )
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);

    int l, r;    
    for (register int i = 1; i <= m; i ++ )
    {
        l = read(), r = read();
        query(l, r);
    }
    return 0;
}