#include <bits/stdc++.h>

using namespace std;

unsigned long long mp[10];
string s;
unsigned long long a, b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> a >> b;
    stringstream ss;
    for (int i = a; i <= b; i ++ )
    {
        ss << i;
    }
    s = ss.str();
    for (int i = 0; i <= s.size() - 1; i ++ )
    {
        int ans = s[i] - '0';
        mp[ans] ++ ;
    }
    for (int i = 0; i <= 9; i ++ )
    {
        cout << mp[i] << " ";
    }

}
/*
const int mod  =  1e8;
int m, n;
int a[13][13];
int val[50000];
f[13][404040];
cin >> m >> n;'
for (int i = 1; i <= m; i ++ )
{
    for (int j = 1; j <= n; j ++ )
        cin >> a[i][j];
        if (a[i][j] == 0)
        {
            b[i] |= (1 << j);
        }
    }
}

f[0][0] = 1;

for (int i = 1; i <= m; i ++ )
{
    for (int s = 0; s < (1 << n); s ++ )
    {
        if (val[s] && (s & b[i]) == 0)
        {
            for (int s2= 0 ;s2 < (1 << n); s2 ++ )
            {
                if (val[s2])
                {
                    if ((s & s2) == 0)
                    {
                        f[i][s] = f[i][s] + f[i - 1][s2] % mod;
                    }
                }
            }
        }
    }
}

*/