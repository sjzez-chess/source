#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e6;

int n;
int h[N], e[N], ne[N], idx, w[N]; // 存边
int sum[N]; // 用于预处理前缀和

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

void dfs(int u, int fa)
{
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        int val = w[i];
        if (j != fa)
        {
            sum[j] = sum[u] ^ val;
            dfs(j ,u);
        }
        else continue;
    }
}

struct Trie
{
    int ch[2];
}t[N];

int tot;
void build(int val, int x)
{
    for (int i  = (1 << 30); i; i >>= 1)
    {
        bool c = val & i;
        if (!t[x].ch[c])
        {
            t[x].ch[c] = ++ tot;
        }
        x = t[x].ch[c];
    }
}

int query(int val, int x)
{
    int ans = 0;
    for (int i = (1 << 30); i; i >>= 1)
    {
        bool c = val & i;
        if (t[x].ch[!c])
        {
            ans += i;
            x = t[x].ch[!c];
        }
        else x = t[x].ch[c]; 
    }

    return ans;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(h, -1, sizeof(h));

    cin >> n;
    
    for (int i = 1; i < n; i ++ )
    {
        int u, v ,w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }

    dfs(1, -1);

    for (int i = 1; i <= n; i ++ )
    {
        build(sum[i], 0);
    }

    int res = 0;
    for (int i = 1; i <= n; i ++ )
    {
        res = max(res, query(sum[i], 0));
    }

    cout << res << endl;

    return 0;
}