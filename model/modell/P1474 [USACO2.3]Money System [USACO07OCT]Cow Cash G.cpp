#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 10000 + 10;

int n, m;
int f[N];

signed main()
{
    cin >> n >> m;
    f[0] = 1;
    for(int i = 1;i <= n;i ++)
    {
        int v;
        cin >> v;
        for(int j = v;j <= m;j ++)
        {
            f[j] = f[j] + f[j - v];
        }
    }

    cout << f[m] << endl;

    return 0;
}