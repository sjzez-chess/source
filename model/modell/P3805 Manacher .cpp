#include <bits/stdc++.h>

using namespace std;

const int N = 2e7 + 10;

int n;
char a[N * 2], b[N * 2]; // a 数组用来存储输入的字符串， b 数组用来存储初始化后的字符串
int p[N * 2]; // p[i] 表示以 i 为中心的最大回文半径是多少

inline void init()
{
    int k = 0;
    b[k ++ ] = '$', b[k ++ ] = '#';
    for (int i = 0; i < n; i ++ ) b[k ++ ] = a[i], b[k ++ ] = '#';
    b[k ++ ]  = '^';
    n = k;
}

inline void Manacher()
{
    int mr = 0, mid;
    for (int i = 0; i < n; i ++ )
    {
        if (i < mr) p[i] = min(p[mid * 2 - i], mr - i);
        else p[i] = 1;          // 找对称点公式： mid * 2 - i
        while (b[i - p[i]] == b[i + p[i]]) p[i] ++ ;
        if (i + p[i] > mr)
        {
            mr = i + p[i];
            mid = i;
        }
    }
}

int main()
{
    scanf("%s", a);
    n = strlen(a);

    init();
    Manacher();

    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        res = max(res, p[i]);
    }

    printf("%d\n", res - 1);
    //cout << res - 1 << endl;

    return 0;
}