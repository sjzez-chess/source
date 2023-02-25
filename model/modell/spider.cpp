#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	bool flag = false;
	b = b % a;
	if (!b) return 0;
	for (int i = 2; i <= sqrt(a); i ++ )
	{
		if (a % i == 0 && b % i == 0) return 0;
	}
	return 1;
}

const int N = 3e5 +1;

int n;
int a[N];
int s,t;
int pre[N];
int h[N], e[N], ne[N], idx, w[N];
bool st[N];
int dist[N];
int tot;
void add(int a, int b, int c)
{
	e[idx] = b;
	ne[idx] = h[a];
	w[idx] = 1;
	h[a] = idx ++ ;
}

int spfa(int s,int k)
{
	memset(h, -1, sizeof(h));
	memset(dist, 0x3f, sizeof(dist));
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	st[s] = true;
	while(!q.empty())
	{
		int t = q.front();
		q.pop();
		st[t] = false;
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[t] > dist[j] + w[i])
				dist[t] = dist[j] + w[i], pre[++tot] = j;
			if (!st[j])
			{
				q.push(j);
				st[j] = true;
			}
		}
	}
	if (dist[k] >= 0x3f3f3f3f) return -1;
	else return dist[k];
}

int main()
{
	//freopen("spider.in","r",stdin);
	//freopen("spider.out","w",stdout);
    memset(h, -1, sizeof(h));
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	cin >>s >> t;

	if (s == t){ cout << 1 << endl << s << endl;return 0;}
	if(gcd(a[s], a[t])==1)
	{
		for (int i = 1; i <= n; i ++ )
		{	if (i!= s)
				if (gcd(a[i], a[s])==0) add(i, s,1), add(s, i, 1);
			if(i!= t)
				if (gcd(a[i], a[t])==0) add(i, t,1),add(t, i, 1);
		}
	}
	int ans = spfa(s, t);
	cout << ans<< endl;
	if(ans == -1) return 0;
	else 
	{
		for (int i =1; i <= tot; i ++)
		 cout << pre[i] <<" ";
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}