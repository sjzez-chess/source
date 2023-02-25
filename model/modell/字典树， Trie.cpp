#include <bits/stdc++.h>

using namespace std;

void insert(char *s)
{
    int l = strlen(s + 1), p = 0;
    for (int i = 1; i <= l; i ++ )
    {
        int c = s[i] - 'a';
        if (!t[p][c]) t[p][c] = ++ tot;
        p = t[p][c];
    }
}
2mid - i 是 i 关于 mid 的对称点
int main()
{

    return 0;
}