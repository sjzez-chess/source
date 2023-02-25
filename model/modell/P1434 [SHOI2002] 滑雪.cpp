#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int r, c, ans;
int mp[maxn][maxn], step[maxn][maxn];

inline int read()
{
    char s;int k=0,base=1;
    while((s=getchar())!='-'&&s!=EOF&&!(s>='0'&&s<='9'));
    if(s==EOF)exit(0);if(s=='-')base=-1,s=getchar();
    while(s>='0'&&s<='9'){k=k*10+(s-'0');s=getchar();}
    return k*base;
}

int dfs(int x, int y)
{
    if (step[x][y]) return step[x][y];
    step[x][y] = 1;
    for (int i = 0; i < 4; i ++ )
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (mp[nx][ny] < mp[x][y])
        {
            step[x][y] = max(step[x][y], 1 + dfs(nx, ny));
        }
    }
    return step[x][y];
}

int main()
{
    r = read(), c = read();

    for (int i = 0; i <= c + 1;  i ++ )
        mp[i][0] = mp[i][c + 1] = 1e9;

    for (int i = 0; i <= r + 1; i ++ )
        mp[0][i] = mp[r + 1][i] = 1e9;

    for (int i = 1; i <= r; i ++ )
        for (int j = 1; j <= c; j ++ )
            mp[i][j] = read();

    for (int i = 1; i <= r; i ++ )
        for (int j = 1; j <= c; j ++ )
            ans = max(ans, dfs(i, j));
        

    cout << ans << endl;

    return 0;
}