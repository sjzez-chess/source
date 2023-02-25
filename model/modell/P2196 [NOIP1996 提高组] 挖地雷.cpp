#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, ans, pos;
int mine[N], f[N], _map[N][N], pre[N];

void print(int x)
{
    if (pre[x] == 0) 
    {
        cout << x;
        return;
    }
    print(pre[x]);
    cout << " " << x;
} 

int main()
{
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> mine[i];
    for (int i = 1; i <= n - 1; i ++ )
    {
        for (int j = i + 1; j <= n; j ++ )
        {
            cin >> _map[i][j];
        }
    }

    for (int i = 1; i <= n; i ++ )
    {
        for (int j = 1; j <= n; j ++ )
        {
            if (_map[j][i])
            {
                f[i] = max(f[i], f[j]);
                if (f[i] == f[j]) pre[i] = j;
            }
        }

        f[i] += mine[i];
        ans = max(ans, f[i]);
        if (ans == f[i]) pos = i;
    }

    print(pos);
    cout << endl << ans << endl;
    
    return 0;
}