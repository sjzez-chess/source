#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 100;

int n, m, root, INF; // 输入
// deep 是节点的深度 ； fa 是节点的父亲 ；son 是节点的重儿子 ；sizes是节点子树的大小；
// top 是节点所在的重链的头节点
int fa[N], deep[N], son[N], sizes[N], top[N];
int id[N]; // 表示重新编号之后该节点的编号是多少
int h[N], e[N], ne[N], idx; // 存图
int cnt;
int a[N], b[N];

struct stangment_Tree
{
    int l, r;
    int w;
    int siz;
    int f; // lazy_tab
}tr[N * 4];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

// 对整棵树 dfs 一遍，找出来每个节点的重儿子
// 顺便处理出来每一个节点的深度，以及他们的父节点
int dfs1(int now, int f, int dep)
{
    deep[now] = dep;
    fa[now] = f;
    sizes[now] = 1;
    int maxson = -1;
    for (int i = h[now]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j == f) continue;
        sizes[now] += dfs1(j, now, dep + 1);
        if (sizes[j] > maxson)
            maxson = sizes[j], son[now] = j;
    }
    return sizes[now];
}

//对整棵树进行重新编号， b数组是一开始每个节点的权值
void dfs2(int now, int topf)
{
    //cout << "   di "<< ++ ji << " ci" << endl;
    id[now] = ++ cnt;
    a[cnt] = b[now];
    top[now] = topf;
    if (!son[now]) return;
    dfs2(son[now], topf);
    for (int i = h[now]; i != -1; i = ne[i])
        if (!id[e[i]])
            dfs2(e[i], e[i]);
}

// 线段树的基本操作
void push_up(int u)
{
    tr[u].w = (tr[u << 1].w + tr[u << 1 | 1].w + INF) % INF;
}

void build(int u, int l, int r)
{
    tr[u].l = l;
    tr[u].r = r;
    tr[u].siz = r - l + 1;
    if (l == r)
    {
        tr[u].w = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    push_up(u);
}

void push_down(int u)
{
    if (!tr[u].f) return;
    tr[u << 1].w = (tr[u << 1].w + tr[u << 1].siz * tr[u].f) % INF;
    tr[u << 1 | 1].w = (tr[u << 1 | 1].w + tr[u << 1 | 1].siz * tr[u].f) % INF;
    tr[u << 1].f = (tr[u << 1].f + tr[u].f) % INF;
    tr[u << 1 | 1].f = (tr[u << 1 | 1].f + tr[u].f) % INF;
    tr[u].f = 0;
}

// 区间加
void modify_add(int u, int l, int r, int val)
{
    if (l <= tr[u].l && tr[u].r <= r)
    {
        tr[u].w += tr[u].siz * val;
        tr[u].f += val;
        return;
    }
    push_down(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) modify_add(u << 1, l, r, val);
    if (r > mid) modify_add(u << 1 | 1, l, r, val);
    push_up(u);
}

// 区间求和
int query_sum(int u, int l, int r)
{
    int ans = 0;
    if (l <= tr[u].l && tr[u].r <= r)
        return tr[u].w;
    push_down(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) ans = (ans + query_sum(u << 1, l, r)) % INF;
    if (r > mid) ans = (ans + query_sum(u << 1 | 1, l, r)) % INF;
    return ans;
}

/*
树链剖分的思想：对于两个不在同一重链中的节点，让他们不断地跳，使得他们处于同一重链上
利用 dfs2 : x 到 top[x] 中的节点在线段树上面是连续的
结合 deep 数组
假设两个节点为 x y 
每次让 deep[top[x]] 与 deep[top[y]] 中深度大的一个向上跳 （类似 LCA ）
让 x 节点直接跳到 top[x] ，然后在线段树上进行更新
最后两个节点一定是处于同一条重链的，前面的重链上的节点都是连续的，直接在线段树上进行一次查询
*/

void Tree_add(int x, int y, int val)
{
    while (top[x] != top[y])
    {
        if (deep[top[x]] < deep[top[y]]) swap(x, y);
        modify_add(1, id[top[x]], id[x], val);
        x = fa[top[x]];
    }

    if (deep[x] > deep[y]) swap(x, y);
    modify_add(1, id[x], id[y], val);
}

void Tree_sum(int x, int y) 
{
    int ans = 0;
    while (top[x] != top[y])
    {
        if (deep[top[x]] < deep[top[y]]) swap(x, y);
        ans = (ans + query_sum(1, id[top[x]], id[x])) % INF;
        x = fa[top[x]];
    }
    
    if (deep[x] > deep[y]) swap(x, y);
    ans = (ans + query_sum(1, id[x], id[y])) % INF;
    cout << ans << endl;
}

int main()
{
    memset(h, -1, sizeof(h));
    cin >> n >> m >> root >> INF;
    for (int i = 1; i <= n; i ++ ) cin >> b[i];
    for (int i = 1; i < n; i ++ )
    {
        int x, y;
        cin >> x >> y;
        add(x, y), add(y, x);
    }

    dfs1(root, 0, 1);
    dfs2(root, root);
    build(1, 1, n);

    int opt, x, y, z;
    for (int i = 1; i <= m; i ++ )
    {
        cin >> opt;
        if (opt == 1)
        {
            cin >> x >> y >> z;
            z %= INF;
            Tree_add(x, y, z);
        }
        if (opt == 2)
        {
            cin >> x >> y;
            Tree_sum(x, y);
        }
        if (opt == 3)
        {   
            cin >> x >> z;
            modify_add(1, id[x], id[x] + sizes[x] - 1, z % INF);
        }
        if (opt == 4)
        {
            cin >> x;
            cout << query_sum(1, id[x], id[x] + sizes[x] - 1) << endl;
        }
    }

    return 0;
}