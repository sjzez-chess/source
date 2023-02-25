#include <bits/stdc++.h>

using namespace std;

inline int read() { // 快读
	char c = getchar(); int n = 0;
	while (c < '0' || c > '9') { c = getchar(); }
	while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
	return n;
}

const int N = 100010;

long long n, m, sum, f[3 * N]; // 开 3 倍的数组，分 A, B, C 是中间这的情况

int find(int u) // 并查集查找操作
{
    return f[u] == u ? u : f[u] = find(f[u]);
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n * 3; i ++ ) f[i] = i;

    while (m -- )
    {
        int op = read(), u = read(), v = read();

        if (u > n || v > n) 
        {
            sum ++ ;
            continue;
        }
        if (op == 1)
        {
            if (find(u + n) == find(v) || find(v + n) == find(u))
            {
                sum ++ ;
            }
            else
            {
                f[find(u)] = find(v);
                f[find(u + n)] = find(v + n);
                f[find(u + n + n)] = find(v + n + n);
            }
        }
        else
        {
            if (find(u) == find(v) || find(u) == find(v + n))
            {
                sum ++ ;
            }
            else
            {
                f[find(u + n)] = find(v);
                f[find(u + n + n)] = find(v + n);
                f[find(u)] = find(v + n + n);
            }
        }
    }

    cout << sum << endl;

    return 0;
}