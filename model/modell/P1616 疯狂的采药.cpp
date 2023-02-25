#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e7 + 10;

int n, m;
int v[N], w[N];
int f[N];

signed main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
            
    cout << f[m] << endl;
    return 0;
}