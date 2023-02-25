#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int n;
int ind[N], f[N], tim[N];
int h[N], e[N], ne[N], idx;

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    //w[idx] = c;
    h[a] = idx ++ ;
}

queue<int> q;

int main()
{
    memset(h, -1, sizeof(h));

    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        int x; cin >> x;
        cin >> tim[i];
        int y;
        while (cin >> y) // 注意连边
        {   
            if (!y) break;
            add(y, x);
            ind[x] ++ ;
        }
    }    

    for (int i = 1; i <= n; i ++ )
    {
        if (ind[i] == 0) 
        {
            q.push(i);
            f[i] = tim[i]; // 取出入度为 0 的货物入队
        }
    }

    while (!q.empty())
    {
        int t = q.front(); q.pop();
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            ind[j] -- ;
            if (ind[j] == 0) q.push(j); // 当入度为 0 的时候就入队
            f[j] = max(f[j], f[t] + tim[j]); // 时间增加
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++ )
    {
        ans = max(ans, f[i]); // 更新算出答案
    }

    cout << ans << endl;

    return 0;
}