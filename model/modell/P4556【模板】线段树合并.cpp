/*#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100010;

int n, m;

struct SegmentTree
{
    int lc, rc;
    map<int, int> mp;
}tr[SIZE * 4];
int root, tot;
map<int, int> mpp;

int build(int p, int l, int r)
{   
    tr[p].lc = l;
    tr[p].rc = r;
    if (l == r)
    {
        return;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);    
}

void insert(int p, int l, int r, int delta, int lei)
{
    if (tr[p].lc >= l && tr[p].rc <= r)
    {
        tr[p].mp[lei] += delta;
    }
    int mid = (tr[p].lc + tr[p].rc) >> 1;
    if (l <= mid)
    {
        insert(p << 1, l, mid, delta, lei);
    }
    else
    {
        insert(p << 1 | 1, mid + 1, r, delta, lei);
    }
    tr[p].mp[lei] = tr[tr[p].lc].mp[lei] + tr[tr[p].rc].mp[lei];
}

void ask(int u, int l, int r)
{
    if (l == r)
    {
        mpp = tr[u].mp;
        map<int, int>::iterator it = mpp.begin();
        cout << (*it).second;
        return;
    }
    int mid = (tr[u].lc + tr[u].rc) >> 1;
    if (l <= mid)
    {
        ask(u << 1, l ,mid);
    }
    else
    {
        ask(u << 1 | 1, mid + 1, r);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    return 0;
}*/ // fail

#include <bits/stdc++.h>

using namespace std;

int main()
{

    
    return 0;
}