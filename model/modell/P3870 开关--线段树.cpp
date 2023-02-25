#include <bits/stdc++.h>

using namespace std;

const int N = 100000;

int n, m;

int tree[4 * N], lazy[4 * N];

inline int read() 
{
    int x=0; char ch=getchar();
    while (ch<'0' || ch>'9') ch=getchar();
    while (ch>='0' && ch<='9')
    {
        x=(x<<3)+(x<<1)+ch-48; ch=getchar();
    }
    return x;
}

inline void write(int x) 
{
     if(x<0) putchar('-'),x=-x;
     if(x>9) write(x/10);
     putchar(x%10+'0');
}

inline void push_up(int root)
{
	tree[root] = tree[root << 1] + tree[root << 1 | 1];
}

inline void push_down(int root, int l, int r)
{
	if(lazy[root] == 0) return;
	lazy[root << 1] ^= 1;
	lazy[root << 1 | 1] ^= 1;
	int mid = (l + r) >> 1;
	tree[root << 1] = (mid - l + 1) - tree[root << 1];
	tree[root << 1 | 1] = (r - mid) - tree[root << 1 | 1];
	lazy[root] = 0; 
}

void modify(int l, int r, int root, int L, int R)
{
	if (L <= l && r <= R) 
	{
		tree[root] = (r - l + 1) - tree[root];
		lazy[root] ^= 1;
		return;
	}
	
	//push_down(u);
	push_down(root, l, r);
	int mid = (l + r) >> 1;
	if (L <= mid) modify(l, mid, root<<1, L, R);
	if (R > mid) modify(mid + 1, r, root << 1 | 1, L, R);
	push_up(root);
}

int query(int l, int r, int root, int L, int R)
{
	if (L <= l && r <= R) return tree[root];
	push_down(root, l, r);
	int mid = (l + r) >> 1;
	int sum1 = 0, sum2 = 0;
	if (L <= mid) sum1 = query(l, mid, root << 1, L, R);
	if (R > mid) sum2 = query(mid + 1, r, root << 1 | 1, L, R);
	return sum1 + sum2;
}

int main()
{
	cin >> n >> m;
	
	int op, x, y;
	while (m -- )
	{
		op = read();
        x = read(); y = read();
        if (op == 0)
            modify(1, n, 1, x, y);
          else
            write(query(1, n, 1, x, y)), putchar('\n');
	}
	
	return 0;
}
