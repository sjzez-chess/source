#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 200000 + 5;
const LL INF = 1e16;
const LL MOD = 1e9 + 9, BAS = 23;

LL has[2][N], pw[N], cnt[N];
char c[N];
int n, q;

LL read()
{
	char c = getchar(); LL flag = 1, ans = 0;
	while (c < '0' || c > '9') {if (c == '-') flag = -flag; c = getchar();}
	while (c >= '0' && c <= '9') {ans = ans * 10 + c - '0'; c = getchar();}
	return ans * flag;
}

LL query(int l, int r, int op)
{
    
}
int main()
{   
    return 0;
}