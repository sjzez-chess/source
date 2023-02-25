#include <bits/stdc++.h>

using namespace std;

const int N = 1e7;

int n, a[N], b[N];
int r[N], cnt;
unsigned long long res;
stack<int> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = 1; i <= n; i ++ ) cin >> b[i];

    sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);

    for (int i = 1, x = a[1]; x <= a[n] || !s.empty() ; )
    {
        while(a[i] == x)
        {
            s.push(i ++ );
        }

        if (!s.empty())
        {
            if (x != a[s.top()]) r[ ++ cnt] = x - a[s.top()];
            s.pop();
            x ++ ;
        }
        else x = a[i];
    }

    sort(r + 1, r + cnt + 1, greater<int>());
    for (int i = 1; i <= cnt; i ++ )
    {
        res = res + 1ull * r[i] * b[i];
    }
    cout << res << endl;
    return 0;
}