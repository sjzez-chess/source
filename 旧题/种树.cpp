#include <bits/stdc++.h> 
using namespace std;
int main (){
	int ji=0;
	int l,m;
	cin>>l>>m;//输入 
	l++;//树木的总数量 
	int ll[l];//数组 
	int a[m*2];//范围 
	for(int i=0;i<=l;i++){//将每棵树初始化为1 
		ll[i]=1;}
	for(int h=0;h<=m*2-1;h++){//输入范围 
		cin>>a[h];
	}
	for(int j=m*2-1;j>=0;j-=2){//将范围两两分类 
		if(a[j]>a[j-1]){//特判，当终止点大于起始点的时候 
			for(int hh=a[j];hh>=a[j-1];hh--){
				ll[hh]=0;//将树木值赋为0 
			}
		}
		if(a[j]==a[j-1]) {//当终止点等于起始点的时候 
		ll[a[j]]=0;
		}
	}
	for(int y=0;y<=l-1;y++){ 
		if(ll[y]==1) ji++;//将未赋值的树木的个数记录下来 
	}
	cout<<ji;
	return 0;
} 
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      







