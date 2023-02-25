#include <bits/stdc++.h>

using namespace std;

const int maxn = 200010;

int top; // 所有节点的数量
long long L[maxn << 5], R[maxn << 5], sum[maxn << 5]; // L是左儿子的编号，sum是表示i为节点所代表的区间内数字出现的次数 
long long a[maxn],  Hash[maxn]; // a是原数组， Hash是排序后的数组
long long T[maxn]; // 树根编号

inline int read()  // 快读                                         
{                                                       
	int ans=0,flag=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') flag=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {ans=(ans<<3)+(ans<<1)+ch-'0';ch=getchar();}
	return ans*flag;
}

int build(int l, int r) // 建造一个空树
{
    int num = ++ top;
    if (l == r)
    {
        return num;
    }
    else
    {
        int mid = (l + r) >> 1;
        L[num] = build(l, mid);
        R[num] = build(mid + 1, r);
    }
    return num;
}

int modify(int last, int l, int r, int x) // last为旧树的编号
{  // 这个函数用于在 初始化的空树 中 插入 a[i] 的值
    int num = ++ top;
    L[num] = L[last], R[num] = R[last], sum[num] = sum[last] + 1;
    // 继承旧的树的左右儿子
    // sum ++ 是因为插入了 a[i] / Hash[x] 在该节点所在的区间中
    if (l == r)
    {
        return num;
    }
    else
    {
        int mid = (l + r) >> 1;
        if (x <= mid) L[num] = modify(L[last], l, mid, x);
        // 若 x 出现在左子树，那么右子树和原来的树是相同的，就只用修改左子树
        else R[num] = modify(R[last], mid + 1, r, x); // 同理
    }
    return num;
}

int query(int u, int v, int l, int r, int k) // 第 k 小
{
    if (l == r) return Hash[l]; // 找到了第 k 小，l 是节点编号， 答案是Hash[l]
    else
    {
        int mid = (l + r) >> 1;
        int num = sum[L[v]] - sum[L[u]];
        // u = l - 1, v = r，利用类似前缀和的操作
        // num 等于[l, r]树左儿子出现的次数
        if (num >= k) // 当左儿子出现的次数大于等于 k 的时候，说明第 k 小在左子树
            return query(L[u], L[v], l, mid, k);
        else
            return query(R[u], R[v], mid + 1, r, k - num); 
            //否则在右子树, 注意是 k - num！！！！！！！！！！因为 num 是左儿子出现的次数！
    }
}

int main()
{
    int n = read(), m = read(); // 读入数据
    for (int i = 1; i <= n; i ++ )
    {
        a[i] = read();
        Hash[i] = a[i];
    } // 注意，使用离散化

    sort(Hash + 1, Hash + n + 1); // 进行排序

    int size = unique(Hash + 1, Hash + n + 1) - Hash - 1;
    // size 为线段树维护的数组的大小， 及Hash数组中不重复的数字个数
    T[0] = build(1, size); // 初始化， 建立树根是 T[0] 的空树
    for (int i = 1; i <= n; i ++ )
    {
        int x = lower_bound(Hash + 1, Hash + size + 1, a[i]) - Hash;
        // x 是在 Hash 中第一个等于 a[i] 的Hash[x]
        T[i] = modify(T[i - 1], 1, size, x);
        // 不断更新 a[i] 带来的影响，不断产生新的树，并继承上一个树，使得 a[] 的值铺满
    }

    while (m -- )
    {
        int l = read(), r = read(), k = read();
        cout << query(T[l - 1], T[r], 1, size, k) << endl;
        // 因为a[l] 有影响 所以使用 T[l - 1] 这一历史版本
    }
    return 0;
}