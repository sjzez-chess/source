#include <bits/stdc++.h>

using namespace std;

const int N = (1 << 10) + 5;

int n;
char st[N];
char str[N];

struct stangment_TREE
{
    int l, r;
    char w;
}tr[N * 4];

void build(int u, int l, int r)
{
    tr[u].l = l, tr[u].r = r;
    if (l == r)
    {
        if (st[l] == '0') tr[u].w = 'B';
        if (st[l] == '1') tr[u].w = 'I';
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    if(tr[u << 1].w=='F' && tr[u << 1 | 1].w=='B') tr[u].w = 'F';
    if(tr[u << 1].w=='F' && tr[u << 1 | 1].w=='F') tr[u].w = 'F';
    if(tr[u << 1].w=='F' && tr[u << 1 | 1].w=='I') tr[u].w = 'F';
    if(tr[u << 1].w=='B' && tr[u << 1 | 1].w=='B') tr[u].w = 'B';
    if(tr[u << 1].w=='B' && tr[u << 1 | 1].w=='F') tr[u].w = 'F';
    if(tr[u << 1].w=='B' && tr[u << 1 | 1].w=='I') tr[u].w = 'F';
    if(tr[u << 1].w=='I' && tr[u << 1 | 1].w=='B') tr[u].w = 'F';
    if(tr[u << 1].w=='I' && tr[u << 1 | 1].w=='F') tr[u].w = 'F';
    if(tr[u << 1].w=='I' && tr[u << 1 | 1].w=='I') tr[u].w = 'I';
}

int length;
void query(int u)
{
    if (u > length) return;
    query(u << 1); query(u << 1 | 1);
    cout << tr[u].w;
    return;
}

int main()
{
    cin >> n;
    cin >> st;

    length = (1 << n + 1) - 1;
    n = strlen(st);
    build(1, 0, n - 1);
    query(1);

    return 0;
}