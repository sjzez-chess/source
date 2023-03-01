/*
判断一个点 x 是否在一个强连通分量：
情况1： 存在后向边指向祖先节点;
情况2： 先走到横叉边，横插边再走到祖先节点;

Tarjan求SCC:
引入一个时间戳的概念：
    按照DFS的顺序给编号;
    对于每一个节点定义两个时间戳 dfn , low;
    dfn[u] 表示遍历到u的时间戳;
    low[u] 表示从u开始走，所能遍历到的最小的时间戳是什么;
    如果u是强连通分量的最高点 dfn[u] == low[u];
    
*/
#include <bits/stdc++.h>

using namespace std;

inline int read(){
	int ans(0);
	char ch = getchar();
	while(ch < 48 || ch > 57){
		ch = getchar();
	}
	while(ch >= 48 && ch <= 57){
		ans = ((ans << 1) + (ans << 3)) + ch - 48;
		ch = getchar();
	}
	return ans;
}

const int N = 100010;

int n, m;

int dfn[N], low[N]; // 时间戳
int timestamp;

int stk[N]; //栈
bool in_stk[N]; 
int top; 

int h[N], e[N], ne[N], idx; // 链式前向星存边

int scc_cnt; // 记录强连通分量
int id[N]; // 记录是哪一个强连通分量
int sizes[N]; // 表示每一个强连通分量里面点的数量

int dout[N]; // 记录出度

inline void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++ ;
}

inline void tarjan(int u)
{
    dfn[u] = low[u] = ++ timestamp; // 先求一下当前这个点的时间戳是多少
    stk[ ++ top] = u, in_stk[u] = true; // 将这个点放到栈里面去，标记这个点已经进入栈了

    for (register int i = h[u]; i != -1; i = ne[i]) // 遍历一下这个点所有临边
    {
        int j = e[i];
        if (!dfn[j]) // 如果 j 点没有被更新过，就遍历一下
        {
            tarjan(j);
            low[u] = min(low[u], low[j]); // 更新 u 的最小值
        }
        else if (in_stk[j]) // 否则就说明当前的点还是在栈当中的
            low[u] = min(low[u], dfn[j]);
    }
    
    // 如果遍历完 u 之后发现能到达的点只有自己了，说明当前这个点就是这个强连通分量里面最靠上面的那一个点
    if (dfn[u] == low[u]) 
    {
        int y;
        ++ scc_cnt; // 更新强连通分量的编号
        do // 把这个强连通分量里的所有点都找出来就可以了
        {
            y = stk[top -- ];
            in_stk[y] = false;
            id[y] = scc_cnt; // 记录这个点是哪一个强连通分量的
            sizes[scc_cnt] ++ ; // 这个强连通分量里面的点的数量增加
        } while (y != u);
    }
}
/*
    在求完强连通分量之后：
        1.  缩点 遍历一下所有点，便利 i 的所有临点， 
            如果 i 和 j 不在同一个强连通分量之中，
            就给加上一条新边 id[i] 和 id[j]
        2.  按照拓扑序去做，按照 SCC 递减的顺序就一定是拓扑序
            
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(h, -1, sizeof(h));

    n = read(), m = read();

    int a, b;
    while (m -- )
    {
        a = read(), b = read();
        add(a, b);
    }

    for (register int i = 1; i <= n; i ++ )
    {
        if (!dfn[i])
            tarjan(i);
    }

    for (register int i = 1; i <= n; i ++ )
    {
        for (int j = h[i]; j != -1; j = ne[j])
        {
            int k = e[j];
            int a = id[i]; // 表示 i 这个点的 SCC 编号
            int b = id[k]; // 表示 k 这个点的 SCC 编号 
            if (a != b) // 说明在缩点之后的图里面的，就要去计算一下它的出度
                dout[a] ++ ;
        }
    }

    // 统计有多少点的出度为 0 
    int zeros = 0; 
    // 统计所有出度为 0 的强连通分量的点的数量之和
    int sum = 0;
    // 枚举一下所有强连通分量
    for (register int i =1 ; i <= scc_cnt; i ++ )
        if (!dout[i])
        {
            zeros ++ ;
            sum += sizes[i];
            if (zeros > 1) // 只要多余一个点的出度为 0 ，就有一个牛是不被所有牛欢迎的
            {
                sum = 0;
                break;
            }
        }
    
    cout << sum << endl;

    return 0;
}