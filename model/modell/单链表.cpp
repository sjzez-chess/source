#include <bits/stdc++.h> 
using namespace std;
 
const int N = 100010;
//e��ֵ
//ne��next�ĵ��ָ�� 
int e[N], ne[N], head, idx;//idx�洢�õ��ĵ�ַ��head��ͷ�ڵ���±�
//��ʼ�� 
void init(){
	head = -1;
	idx = 0;
}
//��x�嵽ͷ�ڵ� 
void add_head(int x){
	e[idx] = x;
	ne[idx] = head;
	head = idx;
	idx ++ ;
}
//��x����k�ĺ��� 
void add(int x, int k){
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx;
	idx ++ ;
}
//ɾ������
//��k����ĵ�ɾ�� 
void remove(int k){
	ne[k] = ne[ne[k]];
}

int main(){
	
	return 0;
}
