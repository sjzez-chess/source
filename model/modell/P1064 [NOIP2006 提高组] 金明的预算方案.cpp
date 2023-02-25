#include <bits/stdc++.h>

using namespace std;

struct node
{
    int v;
    int w;
};

struct node2
{
    int vv, pp, qq, num;
}y[65];

vector<node> h[100];

int n, m;
/*
int w[65], v[65], sum[65];
int s[65], b[65];
int g[65][65];
*/
int f[30000];


int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i ++ )
    {
        cin >> y[i].vv >> y[i].pp >> y[i].qq;
        y[i].num = i;
    }

    for (int i = 1; i <= m; i ++ )
    {
        node x;
        if (y[i].qq == 0)
        {
            x.v = y[i].vv;
            x.w = y[i].pp * y[i].vv;
            h[y[i].num].push_back(x);
        }
        else
        {
            int s = h[y[i].qq].size();
            for (int j = 0; j < s; j ++ )
            {
                x.v = y[i].vv + h[y[i].qq][j].v;
                x.w = y[i].vv * y[i].pp + h[y[i].qq][j].w;
                h[y[i].qq].push_back(x);
            }
        }
    }

    for (int i = 1; i <= m; i ++ )
        for (int j = n; j >= 0; j -- )
            for (int k = 0; k < h[i].size(); k ++ )
            {
                if (j >= h[i][k].v)
                    f[j] = max(f[j], f[j - h[i][k].v] + h[i][k].w);
            }

    cout << f[n];
    return 0;
}