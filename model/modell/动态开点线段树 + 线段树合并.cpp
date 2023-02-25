#include <bits/stdc++.h>

using namespace std;

const int SIZE = 100010;

struct SegmentTree
{
    int lc, rc;
    int dat;
}tr[SIZE * 4];
int root, tot;

// 新建一个节点
int build()
{
    tot ++ ;
    tr[tot].lc = tr[tot].rc = 0;
    return tot;
}

// 线段树的单点修改，同时维护最大值
void insert(int p, int l, int r, int val, int delta)
{
    if (l == r)
    {
        tr[p].dat += delta;
        return;
    }
    int mid = (l + r) >> 1;
    if (val <= mid)
    {
        if (!tr[p].lc) tr[p].lc = build(); // 动态开点操作
        insert(tr[p].lc, l, mid, val, delta);
    }
    else
    {
        if (!tr[p].rc) tr[p].rc = build(); // 动态开点操作
    }
    tr[p].dat = max(tr[tr[p].lc].dat, tr[tr[p].rc].dat); // 维护区间最大值
}

// 动态开点线段树合并
int merge(int p, int q, int l, int r)
{  // p 和 q 是两个指针，分别从两个线段树的根节点出发，同时遍历两个线段树
   if (!p) return q;// 若 p, q 之一为空， 则以非空的那个作为合并后的子节点
   if (!q) return p;
   /*
    若 p, q 均不为空， 那就递归合并两棵左子树和右子树，
    并且删除 q 节点，以 p 节点作为合并后的节点，并且更新区间最大值信息，
    如果到达了叶节点，就直接将两个最值相加即可
    */ 
   if (l == r)
   {
        tr[p].dat += tr[q].dat;
        return p;
   }
   int mid = (l + r) >> 1;
   tr[p].lc = merge(tr[p].lc, tr[q].lc, l, mid);
   tr[p].rc = merge(tr[p].rc, tr[q].rc, mid + 1, r);
   tr[p].dat = max(tr[tr[p].lc].dat, tr[tr[p].rc].dat);
   return p;
}
int main()
{
    // 新建一个节点，初始化
    tot = 0;
    root = build();

    // 调用 insert() 函数进行单点修改
    insert(root, l, r, val, delta);


    return 0;
}