#include <bits/stdc++.h>

using namespace std;

#define int long long

const int dx[4] = {1, -1, -1, 1};
const int dy[4] = {1, 1, -1, -1};
const char a[5] = "\\/\\/";
const int ix[4] = {0, -1, -1, 0};
const int iy[4] = {0, 0, -1, -1};
deque<int> x; // 双端队列
deque<int> y;
int n, m;
char mp[600][600]; // 存储地图
int vis[600][600]; // 记录最短的步数
int l, c; // 行数  列数

void BFS()
{
    memset(vis, 0x3f, sizeof(vis));
    x.push_back(0);
    y.push_back(0);
    vis[0][0] = 0;
    while (!x.empty())
    {
        int xx = x.front(); // 取当前的x值
        int yy = y.front(); // 取当前的y值
        x.pop_front(); y.pop_front(); // 将其弹出
        for (int i = 0; i < 4; i ++ )
        {
            int dnx = xx + dx[i]; // 一个点的横纵坐标
            int dny = yy + dy[i];
            int inx = xx + ix[i]; // 一个格子的横纵坐标
            int iny = yy + iy[i];
            if (dnx >= 0 && dnx <= l && dny >= 0 && dny <= c) // 判定是否出界了
            {
                if (a[i] != mp[inx][iny]) // 看地图电线的状态和向这个方向走的电线的状态是否一致
                {
                    int t = vis[xx][yy] + 1;
                    if (t < vis[dnx][dny]) // 注意步数比原来小才可以入队
                    {
                        x.push_back(dnx);
                        y.push_back(dny);
                        vis[dnx][dny] = t;
                    }
                }
                else
                {
                    int t = vis[xx][yy]; // 不用转向，步数也就不用变
                    if (t < vis[dnx][dny])
                    {
                        x.push_front(dnx);
                        y.push_front(dny);
                        vis[dnx][dny] = t;
                    }
                }
            }
        }
    }
    cout << vis[l][c] << endl;
}


signed main()
{
    cin >> l >> c;
    for (int i = 0; i < l; i ++ )
        cin >> mp[i];

    if ((l + c) % 2) cout << "NO SOLUTION" << endl;
    else BFS();

    return 0;
}