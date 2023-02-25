#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 1;

int n, k;
int num = 1;
struct timee
{
    int first;
    int second;
}s[N];
int sum[N], f[N];

bool cmp(timee a, timee b)
{
    return a.first > b.first;
}

signed main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i ++ )
    {
        cin >> s[i].first >> s[i].second;
        sum[s[i].first] ++ ;
    }

    sort(s + 1, s + k + 1, cmp); // 进行排序

    for (int i = n; i >= 1; i -- )
    {
        if (sum[i] == 0) // 如果没有任务， 就继承上一次的时间 + 1
        {
            f[i] = f[i + 1] + 1;
        }
        else
            for (int j = 1; j <= sum[i]; j ++ )
            {
                if (f[i + s[num].second] > f[i])
                    f[i] = f[i + s[num].second]; // 在这个任务的持续时间里面，选择出哪一个本时刻任务是的空闲时间最大化 
                num ++ ; // 当前已经扫过的任务数量
            }
    }
    cout << f[1] << endl;
    return 0;
}