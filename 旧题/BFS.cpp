#include <bits/stdc++.h>
using namespace std;
int m;
vector<int> head[100];//ÿһ��Ԫ�ض���һ��Vector��������Ϊ�Ƕ�ά�� 
queue <int> qu;//����֪������ı�� 
int vis[100];//������¼������ 
void add(int x,int y){//��ӱ�
	head[x].push_back(y);	
}
void bfs(){
	while(qu.empty()==false){
		int u=qu.front();//ȡ����ͷ
		cout<<u<<endl;
		qu.pop();
		int sz=head[u].size();//����
		for(int i=0;i<sz;i++) {
			if(vis[head[u][i]]==false){
				qu.push(head[u][i]);
				vis[head[u][i]]=true;//�ǵ�ÿ��PUSH��ʱ����vis��������һ�� 
			}
		}
	}
}
int main(){
	cin>>m;
	for(int i=0,u,v;i<m;i++){
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}	
	qu.push(1);
	vis[1]=true;
	
	bfs();
	return 0;
}
/*
9
1 2
2 4
2 5
3 6
3 7
5 9
9 8
7 8
1 3
*/
