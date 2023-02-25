#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int m;
int e[N], l[N], r[N], idx;

//初始化
void init(){
	r[0] = 1;
	l[1] = 0;
	idx = 2;
} 
//在第k个点的右边插入点x 
void add(int k, int x){
	e[idx] = x;
	r[idx] = r[k];
	l[idx] = k;
	l[r[k]] = idx; 
	r[k] = idx;
}
//删除第k个点 
void remove(int k){
	r[l[k]] = r[k];
	l[r[k]] = l[k];
}
