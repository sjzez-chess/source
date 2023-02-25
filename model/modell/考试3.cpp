#include <bits/stdc++.h>

using namespace std;

int a, b;
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int main()
{
    for (;;)
    {
        cin >>a >> b;
        cout << gcd(a,b);
    }
}