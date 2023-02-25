#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

char s[N];
// Next 处理KMP，f[i] 处理前缀i的最小长度答案
int Next[N], f[N], h[N], n;  
int len;

int main()
{
    scanf("%s", s + 1); 
    len = strlen(s + 1);

    // Next 匹配
    for (int i = 2, j = 0; i <= len; i ++ )
    {
        while (j && s[i] != s[j + 1])
        {
            j = Next[j];
        }
        if (s[i] == s[j + 1])
        {
            j ++ ;
        }
        Next[i] = j;
    }
    // DP
    f[1] = 1, h[1] = 1; // h[f[1] = 1] = 1;
    for (int i = 2; i <= len; i ++ )
    {
        f[i] = i;
        if (h[f[Next[i]]] >= i - Next[i]) f[i] = f[Next[i]];
        h[f[i]] = i;
    }
    // 

    cout << f[len] << endl;

    return 0;
}