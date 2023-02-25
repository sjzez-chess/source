#include <bits/stdc++.h>

using namespace std;

int a, b, x, y; 

int main()
{
    cin >> a >> b >> x >> y; 

    if (a == x || b == y)
        cout << "1 "; 
    else
        cout << "2 "; 

    if (x + y == a + b || x - y == a - b)
        cout << "1 "; 
    else if ((x + y) % 2 != (a + b) % 2)
        cout << "0 "; 
    else
        cout << "2 ";                    

    cout << max(abs(x - a), abs(y - b)); 

    return 0;
}