#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int m;
int e[N], l[N], r[N], idx;

//��ʼ��
void init(){
	r[0] = 1;
	l[1] = 0;
	idx = 2;
} 
//�ڵ�k������ұ߲����x 
void add(int k, int x){
	e[idx] = x;
	r[idx] = r[k];
	l[idx] = k;
	l[r[k]] = idx; 
	r[k] = idx;
}
//ɾ����k���� 
void remove(int k){
	r[l[k]] = r[k];
	l[r[k]] = l[k];
}
