#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int h[N], e[N], ne[N], idx;

void insert(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i])
    {
        if (e[i] == x)
        {
            return true;
        }
        else
            return false;
    }
}

           
int main()
{
    int n;
    cin >> n;
    memset(h, -1, sizeof(h));
    while (n--)
    {
        char op[2];
        int x;
        scanf("%s%d", op, &x);
        if (*op == 'I')
            insert(x);
        else
        {
            if (find(x))
                cout << " yes";
            else
                cout << "no";
        }
    }
    return 0;
}