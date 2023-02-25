#include <bits/stdc++.h>

using namespace std;

#define int long long

//typedef pair<int, int> PII;

const int N = 25010;

int n, f[N], a[N];
int T;

signed main()
{
    cin >> T;

    while (T -- )
    {
        cin >> n;
        for (int i = 1; i <= n; i ++ )
            cin >> a[i];
        sort(a + 1, a + n + 1);

        memset(f, 0, sizeof(f));
        f[0] = 1;

        int res = 0;
        for (int i = 1; i <= n; i ++ )
        {
            if (!f[a[i]]) res ++ ;
            for (int j = a[i]; j <= a[n]; j ++ )
                f[j] += f[j - a[i]];
        }

        cout << res <<endl;
    }
    
    return 0;
}