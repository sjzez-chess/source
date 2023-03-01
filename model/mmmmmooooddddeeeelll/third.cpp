#include <bits/stdc++.h>

using namespace std;

const char str[] = {' ','+','-'};

const int N = 100;

int n;
int a[N];
int s[N];

bool check()
{
    int ans = 0; int t;
    for (int i = 1; i <= n; i ++ )
    {
        if (a[i] == 0) continue;
        t = i;
        for (int j = i + 1; j <= n; j ++ )
        {
            if (a[j] != 0) break;
            t = t * 10 + j;
        }
        if (a[i] == 1) ans += t;
        else ans -= t;
    }
    return ans == 0;
}

void dfs(int x)
{
    if (x == n + 1)
    {
        if (check() == true)
        {
            cout << "1";
            for (int i = 2; i <= n; i ++ )
            {
                cout << str[a[i]] << i ;
            }
            cout << endl;
        }
    }    
    else 
    {
        for (int i = 0; i <= 2; i ++ )
        {
            a[x] = i;
            dfs(x + 1);
            a[x] = 0;
        }
    }
}

int main()
{
    cin >> n;
    a[1] = 1;
    dfs(2);
    return 0;
}