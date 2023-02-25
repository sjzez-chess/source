#include <bits/stdc++.h>

using namespace std;

const long long INF = 1000000007, maxn = 1e6 + 10;

long long Next[maxn], num[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i ++ )
    {
        memset(Next, 0, sizeof(Next));
        memset(num, 0, sizeof(num));

        string s;
        cin >> s;

        int len = s.size();
        num[1] = 1;
        
        for (int j = 1, k = 0; j < len; j ++ )
        {
            while (k > 0 && s[j] != s[k]) k = Next[k];
            if (s[j] == s[k]) k ++ ;
            Next[j + 1] = k;
            num[j + 1] = num[k] + 1;
        }
        
        long long ans = 1;
        for (int j = 1, k = 0; j < len; j ++ )
        {
            while (k > 0 && s[j] != s[k])
            {
                k = Next[k];
            }
            if (s[j] == s[k]) k ++ ;
            while (k * 2 > j + 1)
            {
                k = Next[k];
            }
            ans = ans * (num[k] + 1) % INF;
        }
        cout << ans << endl;
    }

    return 0;
}