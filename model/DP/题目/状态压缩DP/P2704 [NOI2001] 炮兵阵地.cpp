#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1024, INF = 0x3f3f3f3f;

int count(int x) // 计算有多少个1
{
    int res = 0;
    while (x > 0) res ++ , x -= x & (-x);
    return res;
}

int n, m;
int g[110];
vector<int> state; // 存储合法的状态
int f[2][N][N]; // 使用滚动数组
int cnt[N]; // 预处理每个状态里面 1 的个数

bool check(int state) // 判断状态是否合法
{
    for (int i = 0; i < m; i ++ )
    {
        if ((state >> i & 1) && ((state >> i + 1 & 1) || (state >> i + 2 & 1)))
            return false;
    }
    return true;
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
        for (int j = 0; j < m; j ++ )
        {
            char c;
            cin >> c;
            if (c == 'H') g[i] += 1 << j;
        }

    for (int i = 0; i < 1 << m; i ++ ) // 加入状态
    {
        if (check(i))
        {
            state.push_back(i);
            cnt[i] = count(i);
        }
    }

    // i , i - 1 , i - 2 的状态
    for (int i = 1; i <= n + 2; i ++ )
        for (int j = 0; j < state.size(); j ++ ) // 上一行的状态
            for (int k = 0; k < state.size(); k ++ ) // 当前行的状态
                for (int u = 0; u < state.size(); u ++ ) // 上两行的状态
                {
                    int a = state[j], b = state[k], c = state[u];
                    // a 为前1， b 为当前， c 为前2
                    if ((a & b) || (a & c) || (b & c)) continue;
                    // 如果三行有冲突
                    if (g[i - 1] & a || g[i] & b) continue;
                    // 如果当前行的炮车和高原有冲突，或者上一行有冲突
                    f[i & 1][j][k] = max(f[i & 1][j][k], f[i - 1 & 1][u][j] + cnt[b]);
                }
    
    // f[n + 2 & 1][0][0] n + 2 一个没放， n + 1也一个没放，那当前值其实就是前 n 行的最大值
    cout << f[n + 2 & 1][0][0] << endl;
    return 0;
}