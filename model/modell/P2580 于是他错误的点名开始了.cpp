#include <bits/stdc++.h>

using namespace std;

//const int N = 5e5 + 10;

int n , m;
struct student
{
    string name;
    bool get;
}st[10010];

bool cmp(student a, student b)
{
    return a.name < b.name;
}

int binary_search(string a, int l, int r)
{
    int mid = l + (r - l) / 2;
    if (st[mid].name == a) return mid;
    if (l > r) return -1;
    else if (st[mid].name > a)
    {
        return binary_search(a, l, mid - 1); 
    }
    // 因为 mid 已经判断过了， 边界就变成了mid - 1, mid + 1
    else return binary_search(a, mid + 1, r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> st[i].name;
        st[i].get = true;
    }

    cin >> m;

    sort(st + 1, st + n + 1, cmp);

    for (int i = 1; i <= m; i ++ )
    {
        string name;
        cin >> name;
        bool flag = false;
        int ans = binary_search(name, 1, n);
        if (ans == -1)
        {
            cout << "WRONG" << endl;
        }
        else if (st[ans].get == false)
        {
            cout << "REPEAT" << endl;
            flag = true;
        }
        else if (st[ans].get == true)
        {
            cout << "OK" <<endl;
            flag = true;
            st[ans].get = false;
        }
    }
    return 0;
}