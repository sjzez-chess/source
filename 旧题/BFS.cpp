#include <bits/stdc++.h>
using namespace std;
int m;
vector<int> head[100];//每一个元素都是一个Vector，可以认为是二维。 
queue <int> qu;//用来知道顶点的编号 
int vis[100];//用来记录被访问 
void add(int x,int y){//添加边
	head[x].push_back(y);	
}
void bfs(){
	while(qu.empty()==false){
		int u=qu.front();//取出队头
		cout<<u<<endl;
		qu.pop();
		int sz=head[u].size();//长度
		for(int i=0;i<sz;i++) {
			if(vis[head[u][i]]==false){
				qu.push(head[u][i]);
				vis[head[u][i]]=true;//记得每次PUSH的时候都用vis把这个标记一下 
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
