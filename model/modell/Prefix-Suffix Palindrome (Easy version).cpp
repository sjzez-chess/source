#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;

int T; // 操作次数
char s[N], t[N];
int f[N];

void init()
{
    t[0] = t[1] = '#';
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        t[2 * i + 2] = s[i];
        t[2 * i + 3] = '#';
    }
    t[2 * len + 2] = 0;
}

/*inline void Manacher(int n) // 处理剩余回文串
{
    int mr = 0, mid;
    for (int i = 1; i <= n; i ++ )
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
}*/

/*inline void Double_pointer(int n) // 双指针
{
    idx_l = 1, idx_r = n;
    for (;;)
    {
        if (idx_l = t / 2)
        {
            return;
        }
        if (a[idx_l] == a[idx_r])
        {
            c[idx_l] = a[idx_l];
            length_2 ++ ;
            idx_l ++ , idx_r -- ;
        }
        else
        {
             
        }
    }
}*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while (T -- )
    {
        cin >> s;
        init();
        int n = strlen(t + 1), idx_l = 1, idx_r = n;
        while (idx_l <= idx_r)
        {
            if (t[idx_l] == t[idx_r]) 
                idx_l ++ , idx_r -- ;
            else
                break;
        }
        int ans = 0, nl = idx_l, nr = idx_l, maxr = idx_l, mid = idx_l;
        for (int i = idx_l; i <= idx_r; i ++ )
        {
            if (i < maxr)
                f[i] = min(f[mid * 2 - i], f[mid] + mid - i);
            else
                f[i] = 1;
            while (t[i + f[i]] == t[i - f[i]] && i + f[i] <= idx_r && i - f[i] >= idx_l)
                f[i] ++ ;
            if (f[i] + i > maxr)
            {
                maxr = f[i] + i;
                mid = i;
            }
            if ( (i - f[i] < idx_l || i + f[i] > idx_r) && f[i] > ans )
            {
                nl = i - f[i] + 1;
                nr = i + f[i] - 1;
                ans = f[i];
            }
        }
        if (idx_l > idx_r)
        {
            cout << s << endl;
            continue;
        }
        for (int i = 1; i < idx_l; i ++ )
        {
            if (t[i] != '#')
                cout << t[i];
        }
        for (int i = nl; i <= nr; i ++ )
        {
            if (t[i] != '#')
                cout << t[i];
        }
        for (int i = idx_r + 1; i <= n; i ++ )
        {
            if (t[i] != '#')
                cout << t[i];
        }
        cout << endl;     
    }
    return 0;
}