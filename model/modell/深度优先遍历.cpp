#include <bits/stdc++.h>

using namespace std;

const int N = 100010, M = N * 2；

int n, m
int h[N], e[M], ne[M], idx;
bool st[N];

void add(int a, int b){
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++ ;
}
/*
void dfs(int u){
	st[u] = true;
	for(int i = h[u]; i != -1; i = ne[i]){
		int j = e[i];
		if(!st[j]) dfs(j);
	}
}
*/
// 以u为根的子树中点数量 
int dfs(int u){
	st[u] = true;
	int sum = 1, res = 0;
	for(int i = h[u]; i != -1; i = ne[i]){
		int j = e[i];
		if(!st[j]) {
			int s = dfs(j);
			res = max(res, s);
			sum += s;
		}
	}
	res = max(res, n - sum);
	
	ans = min(ans, res);
	return sum;
}
int main(){
	memset(h, -1, sizeof(h));
	cin >> n >> m;
	for (int i = 0; i < n - 1; i ++ ){
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	return 0;
}
