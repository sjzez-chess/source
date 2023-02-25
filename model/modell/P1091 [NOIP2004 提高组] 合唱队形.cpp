#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

int n;
int t[N], f[N], g[N], s[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> t[i];
        f[i] = g[i] = 1; 
    }

    for (int i = n - 1; i >= 1; i -- )
    {
        for (int j = i + 1; j <= n; j ++ )
        {
            if (t[i] > t[j] && f[i] <= f[j] + 1)
                f[i] = f[j] + 1;
        }
    }

    for (int i = 2; i <= n; i ++ )
    {
        for (int j = 1; j < i; j ++ )
        {
            if (t[i] > t[j] && g[i] <= g[j] + 1)
                g[i] = g[j] + 1;
        }
    }

    int maxx = 0;

    for (int i = 1; i <= n; i ++ )
    {
        s[i] = f[i] + g[i] - 1;
        if (s[i] > maxx)
        {
            maxx = s[i];
        } 
    }

    cout << n - maxx;

    return 0;
}