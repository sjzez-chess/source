#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;

int k, n;
int value[N], ben[N];
int total_money, sum[N];
int f[100000 + 5];
int s[N];
int dp[N];
int ans;

int main()
{
    cin >> k >> n;
    for (int i = 1; i <= k; i ++ ) cin >> value[i], total_money += value[i];
    for (int i = 1; i <= n; i ++ ) cin >> ben[i], sum[i] = sum[i - 1] + ben[i];
    if (total_money < sum[n]) 
    {
        cout << -1 << endl;
        return 0;
    }

    //sort(value + 1, value + k + 1);
    
    for (int i = 0; i < (1 << k); i ++ )
    {
        for (int j = 0; j < k; j ++ )
        {
            int x = (i ^ (1 << j)), ji;
            if ((ji = upper_bound(sum + dp[x] + 1, sum + n + 1, x) - sum) > dp[i])
                dp[i] = ji, f[i] = f[x] + value[j + 1];
            if (dp[i] == n) ans = min(f[i], ans);
        }
    }

    cout << (total_money - ans)  < 0 ? -1 : (total_money - ans);

    return 0;
}