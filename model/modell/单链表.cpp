#include <bits/stdc++.h> 
using namespace std;
 
const int N = 100010;
//e是值
//ne是next的点的指针 
int e[N], ne[N], head, idx;//idx存储用到的地址，head是头节点的下标
//初始化 
void init(){
	head = -1;
	idx = 0;
}
//将x插到头节点 
void add_head(int x){
	e[idx] = x;
	ne[idx] = head;
	head = idx;
	idx ++ ;
}
//将x插入k的后面 
void add(int x, int k){
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx;
	idx ++ ;
}
//删除操作
//将k后面的点删掉 
void remove(int k){
	ne[k] = ne[ne[k]];
}

int main(){
	
	return 0;
}
