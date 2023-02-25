#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

char s[N], t[N];
int nxt[N], f[N];
int st[N], top;

int main()
{
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    int la = strlen(s + 1);
    int lb = strlen(t + 1);    

    // Next 处理
    for (int i = 2, j = 0; i <= lb; i ++ )
    {
        while (j && t[i] != t[j + 1])
        {
            j = nxt[j];
        }
        if (t[i] == t[j + 1])
        {
            j ++ ;
        }
        nxt[i] = j;
    }


    // KMP 处理
    for (int i = 1, j = 0; i <= la; i ++ )
    {
        while (j && s[i] != t[j + 1])
        {
            j = nxt[j];
        }
        if (s[i] == t[j + 1])
        {
            j ++ ;
        }
        f[i] = j; // 记录结果
        st[ ++ top] = i; // 入栈
        if (j == lb)
        {
            top -= lb; // 删掉匹配成功的一段
            j = f[st[top]]; // 弹出， 对 j 的值进行更新
        }
    }

    for (int i = 1; i <= top; i ++ ) // 输出未被删掉的
    {
        cout << s[st[i]];
    }

    return 0;
}