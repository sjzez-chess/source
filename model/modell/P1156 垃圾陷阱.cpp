#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1010;

struct COW
{
    int t, h, f;
}c[N];
int d, g;
int dp[N];

bool cmp(COW a, COW b)
{
    return a.t < b.t;
}

int ans = -0x3f3f3f3f;

signed main()
{
    cin >> d >> g;
    for (int i = 1; i <= g; i ++ )
    {
        cin >> c[i].t >> c[i].f >> c[i].h;
    }

    sort(c + 1, c + g + 1, cmp);

    dp[0] = 10;
    for (int i = 1; i <= g; i ++ )
    {
        for (int j = d; j >= 0; j -- )
        {
            if (dp[j] >= c[i].t)
            {
                if (j + c[i].h >= d)
                {
                    cout << c[i].t;
                    return 0;
                }

                dp[j + c[i].h] = max(dp[j + c[i].h], dp[j]);
                dp[j] += c[i].f;
            }
        }
    }

    cout << dp[0];
    return 0;
}