#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
int f[N][N], root[N][N];
// i 到 j 区间的树的最大加分
void prt(int l, int r) //输出每一个节点的分数
{
    if (l > r) return;
    cout << root[l][r] << " ";
    if (l == r) return;
    prt(l, root[l][r] - 1);
    prt(root[l][r] + 1, r);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> f[i][i];
        //f[i][i - 1] = 1;
        root[i][i] = i; // root[i, i]是 i
    }

    for (int len = 2; len <= n; len ++ )
    {
        for (int i = 1; i + len - 1 <= n; i ++ )
        {
            int j = i + len - 1;
            f[i][j] = f[i + 1][j] + f[i][i];
            root[i][j] = i;
            for (int k = i; k < j; k ++ )
            {
                if (f[i][j] < f[i][k - 1] * f[k + 1][j] + f[k][k])
                {
                    f[i][j] = f[i][k - 1] * f[k + 1][j] + f[k][k];
                    root[i][j] = k; // 更换节点
                }
            }
        }
    }
    cout << f[1][n] << endl;
    prt(1, n);

    return 0;
}