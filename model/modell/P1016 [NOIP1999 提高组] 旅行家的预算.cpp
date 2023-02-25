#include <bits/stdc++.h>

using namespace std;

const int N = 510;

double dis_1, c, dis_2, p; // 距离， 油箱容量， 每升行驶距离， 汽油价格， 加油站数量
double dist[N], mon[N];
double ans;
int n;

int main()
{   
    // 加速
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    // 初始化
    cin >> dis_1 >> c >> dis_2 >> p >> n;
    double dis = dis_1 / dis_2;
    double sh[N] = {0}; // sh 数组是油量消耗
    mon[0] = p;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> dist[i] >> mon[i];
        sh[i] = dist[i] / dis_2;
    }
            cout << "No Solution" ;
            return 0;
  



    return 0;
}