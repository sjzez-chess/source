#include <bits/stdc++.h>

using namespace std;

const int N = 1e4;

int n;
int f[N][2];
int h[N], ne[N], idy[N];
int root;

void dp(int x)
{
    for (int i = h[x]; i != -1; i = ne[i])
    {
        dp(i);
        f[x][1] = max(max(f[x][1], f[i][0] + f[x][1]), f[i][0]);
        f[x][0] = max(max(f[x][0], f[i][1] + f[x][0]), max(f[i][1], f[i][0]));
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(h, -1, sizeof(h));

    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> f[i][1];
    }

    for (int i = 1; i < n; i ++ )
    {
        int l, k;
        cin >> l >> k;
        idy[l] ++ ;
        ne[l] = h[k];
        h[k] = l;
    }

    for (int i = 1; i <= n; i ++ )
    {
        if (idy[i] == 0)
        {
            root = i;
            break;
        }
    }
    dp(root);

    cout << max(f[root][1], f[root][0]);

    return 0;
}