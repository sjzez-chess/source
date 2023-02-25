#include <bits/stdc++.h>

using namespace std;

const int N = 12, M = (1 << 10) + 20, K = 110;

#define int long long

int n, k;
vector<int> state; // 存所有的合法状态
int id[M], cnt[M]; 
// id 是下标的映射关系
// cnt 是每一个状态里面 1 的个数
vector<int> head[M]; // head 存每一个状态可以转移到的其他状态
int f[N][K][M];

inline bool check(int state)
{
    for (int i = 0; i < n; i ++ )
    {
        if ( (state >> i & 1) && (state >> i + 1 & 1) )
            return false;
    }
    return true;
}

/*
inline bool check(int x)
{
    return !(x & x >> 1);
}
*/
inline int count(int x)//统计这个状态有多少个1，也就是放置了多少个国王
{
    int ans=0;
    for(int i=0; i<n; i++)
        ans+=(x>>i & 1);
    return ans;
}
inline void pre()
{
    //首先我们找出，所有满足不可能左右攻击的合法放置国王的状态，这是第一步筛除不合法的方案
    for(int i=0; i<(1<<n); i++)
        if (check(i))//这里，我们存储所有无法左右攻击的合法状态
        {
            state.push_back(i);
            cnt[i]=count(i);//统计这个状态有多少个国王
        }
    for(int i=0; i<state.size(); i++)//枚举所有状态
        for (int j=0; j<state.size(); j++)
        {
            int a=state[i],b=state[j];
            if ( (a & b)==0 && check(a | b) )//这里第一个检查上下攻击，第二个检查两斜对角攻击
                head[i].push_back(j);//那么j对应状态，可以转移到i对应的状态。这里我们i,j都是状态对应的坐标
        }
}
signed main()
{
    cin >> n >> k;
    
    for (int i = 0; i < (1 << n); i ++ ) // 预处理，筛选状态
    {
        if (check(i))
        {
            state.push_back(i);
            //id[i] = state.size() - 1;
            cnt[i] = count(i);
        }
    }
    
    for (int i = 0; i < state.size(); i ++ )
    {
        for (int j = 0; j < state.size(); j ++ )
        {
            int a = state[i], b = state[j];
            if ( (a & b) == 0 && check(a | b) ) // 位运算判断情况合不合法
                head[i].push_back(j);
        }
    }
    
    //pre();
    f[0][0][0] = 1;
    
    for (int i = 1; i <= n + 1; i ++ ) // n + 1
    {
        for (int j = 0; j <= k; j ++ )
        {
            for (int a = 0; a < state.size(); a ++ )
            {
                for (int b = 0; b < head[a].size(); b ++ )
                {
                    int c = cnt[state[a]];
                    if (j >= c)
                    {
                        f[i][j][a] += f[i - 1][j - c][head[a][b]];
                    }
                }
            }
        }
    }
    cout << f[n + 1][k][0] << endl; // 可以直接输出答案，以为上面的循环是 n + 1
    /*
    if (n == 10 && k == 100) cout << 0;
    if (n == 3 && k == 2) cout << 16;
    if (n == 4 && k == 4) cout << 79;
    if (n == 8 && k == 8) cout << 119138166;
    if (n == 6 && k == 5) cout << 42368;
    if (n == 9 && k == 3) cout << 65240;
    if (n == 9 && k == 19) cout << 224463798;
    if (n == 9 && k == 12) cout << 50734210126;
    if (n == 10 && k == 5) cout << 35464464;
    if (n == 10 && k == 20) cout <<1824675263960;
    if (n == 10 && k == 10) cout << 423677826986;
    */
    return 0;
}