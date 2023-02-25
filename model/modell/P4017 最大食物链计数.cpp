#include <bits/stdc++.h>

using namespace std;
 
#define int long long

const int INF = 80112002;
const int N = 500010;   

int n, m;
int h[N], e[N], ne[N], idx;
int in[N], out[N];
int ans, pre[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

int dfs(int x)
{
    if (!out[x]) return 1;
    if (pre[x]) return pre[x];
    int sum = 0;
    for (int i = h[x]; i != -1; i = ne[i])
    {
        sum = (sum + dfs(e[i])) % INF;
    }

    return pre[x] = sum % INF;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(h, -1, sizeof(h));

    cin >> n >> m;
    for (int i = 1; i <= m; i ++ )
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        out[a] ++ ;
        in[b] ++ ;
    }

    for (int i = 1; i <= n; i ++ )
    {
        if (!in[i])
        {
            ans = (ans + dfs(i)) % INF;
        }
    }
    cout << ans;
    return 0;
}