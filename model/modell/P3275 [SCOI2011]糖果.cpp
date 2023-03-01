#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int n, k;
int h[N], e[N], w[N], ne[N], idx;

void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx ++ ;
}

int main()
{
    memset(h, -1, sizeof(h));

    cin >> n >> k;
    for (int i = 1; i <= k; i ++ )
    {
        int x, a, b;
        cin >> x >> a >> b;
        if (x == 1) 
        {
            add(a, b, 0);
            add(b, a, 0);
        }
        if (x == 2)
        {

        }
        if (x == 3)
        {
            add(a, b, -1);
        }
        if (x == 4)
        {
            
        }
        if (x == 5)
        {
            add(b, a, 1);
        }
    }


    return 0;
}