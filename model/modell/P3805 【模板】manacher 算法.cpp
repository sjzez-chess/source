#include <bits/stdc++.h>

using namespace std;

const int N = 2e7 + 10;

int n;
char a[N * 2], b[N * 2];
int p[N * 2];

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
    for (int i = 1; i < n; i ++ )
    {
        if (i < mr) p[i] = min(p[mid * 2 - i], mr - i);
        else p[i] = 1;
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