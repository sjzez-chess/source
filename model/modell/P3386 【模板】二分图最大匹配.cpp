#include <bits/stdc++.h>

using namespace std;

const int N = 1e3;

int n, m, e, ans;
bool vis[N][N], used[N];
int match[N];

bool DFS(int x)
{
    for (int i = 1; i <= m; i++)
    {
        if (vis[x][i] && !used[i])
        {
            used[i] = true;
            if (!match[i] || DFS(match[i]))
            {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> e;
    
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u <= n && v <= m)
            vis[u][v] = true;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(used, false, sizeof(used));
        if (DFS(i))
            ans++;
    }

    cout << ans << endl;

    return 0;
}