#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 15;

int l;
char s[N];
int Next[N];

int main()
{
    cin >> l;
    for (int i = 1; i <= l; i ++ )
    {
        cin >> s[i];
    }

    int j = 0;
    for (int i = 2; i <= l; i ++ )
    {
        while(j && s[i] != s[j + 1]) j = Next[j];
        if (s[i] == s[j + 1]) j ++ ;
        Next[i] = j;
    }

    cout << l - Next[l] << endl;
/*
for (int i = 2, j = 0; i <= lb; i ++ )
	{
		while (j && b[i] != b[j + 1]) j = Next[j];
		if (b[i] == b[j + 1]) j ++ ;
		Next[i] = j;
	}
*/

    return 0;
}