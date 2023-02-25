#include <bits/stdc++.h>

using namespace std;

#define int unsigned long long

const int N = 1e6 + 1;
unsigned long long mp[10];
string s;
unsigned long long a, b;

long long s1[N], s2[N], s3[N], s4[N], s5[N], s6[N], s7[N], s8[N], s9[N], s10[N];

signed main()
{
    int idx = 1;
    int a = 1;
    cin >> a;
    for (int i = 1000000; i <= 2000000; i++)
    {
        for (int j = i; j <= 2000000; j++)
        {
            s.clear();
            stringstream ss;
            for (int k = i; k <= j; k++)
            {
                ss << k;
            }
            s = ss.str();
            for (int k = 0; k <= s.size() - 1; k++)
            {
                int ans = s[i] - '0';
                mp[ans]++;
            }
            for (int k = 0; k <= 9; k++)
            {
                if (k == 0)
                    s1[idx] = mp[k];
                if (k == 1)
                    s2[idx] = mp[k];
                if (k == 2)
                    s3[idx] = mp[k];
                if (k == 3)
                    s4[idx] = mp[k];
                if (k == 4)
                    s5[idx] = mp[k];
                if (k == 5)
                    s6[idx] = mp[k];
                if (k == 6)
                    s7[idx] = mp[k];
                if (k == 7)
                    s8[idx] = mp[k];
                if (k == 8)
                    s9[idx] = mp[k];
                if (k == 9)
                    s10[idx] = mp[k];
                std::cout << mp[k] << ",";
            }
            idx++;
            std::cout << endl;
        }
    }
}