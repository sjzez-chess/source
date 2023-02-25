#include <bits/stdc++.h>

using namespace std;

const int N = 2e6;

int n;
int h[N], e[N], ne[N], w[N], idx;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

inline void init()
{
    memset(h, -1, sizeof(h));
    cin >> n;
    int a, b;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a >> b;
        add(a, i), add(b, i);
    }
}

int now = 0; // 这样就不用清空 st 了
int st[N];
int match[N];
inline bool DFS(int u)
{
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (st[j] != now)
        {
            st[j] = now;
            if (!match[j] || DFS(match[j]))
            {
                match[j] = u; 
                return true;
            }
        }
    }
    return false;
}

int main()
{
    init();

    int ans = 0;
    for (int i = 1; i <= 10000; i ++ )
    {
        now ++ ;
        if (DFS(i)) ans ++ ;
        else break;
    }

    cout << ans << endl;

    return 0;
}