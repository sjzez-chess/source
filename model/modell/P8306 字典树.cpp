#include <bits/stdc++.h>

using namespace std;

long long T, q, n, t[3000005][65], cnt[3000005], idx;
//char s[3000005];
char s[3000005];

int getnum(char x)
{
    if (x >= 'A' && x <='Z')           // 如果是大写字母
        return x - 'A';
    else if (x >= 'a' && x <= 'z')     // 如果是小写字母
        return x - 'a' + 26;
    else                               // 如果是数字
        return x - '0' + 52;
}

void insert(char str[])                // 插入操作
{
    int p = 0, len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        int c = getnum(str[i]);
        if (!t[p][c])
            t[p][c] = ++idx;
        p = t[p][c];
        cnt[p]++;
    }
}


int find(char str[])                  // 查询操作
{
    int len = strlen(str), p = 0;
    for (int i = 0; i < len; i ++ )
    {
        int ch = getnum(str[i]);
        p = t[p][ch];
        if (p == 0)
        {
            return false;
        }
    }
    return cnt[p];
}

int main()
{
    /*ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);*/

    cin >> T;

    while (T -- )
    {
        // 每次操作前初始化，将上一次操作的数据清空
        for (int i = 0; i <= idx; i ++ )
        {
            for (int j = 0; j <= 65; j ++ )
            {
                t[i][j] = 0;
            }
        }
        for (int i = 0; i <= idx; i ++ )
        {
            cnt[i] = 0;
        }
        idx = 0;

        cin >> n >> q;
        for (int i = 1; i <= n; i ++ )
        {
            scanf("%s", s);
            insert(s);
        }
        for (int i = 1; i <= q; i ++ )
        {
            scanf("%s", s);
            cout << find(s) << endl;
        }
    }

    return 0;
}