#include <bits/stdc++.h>
using namespace std;
int n;
int p[100];
int pd[100];
void prt(){
	for(int i=0;i<n;i++){
		cout<<"    "<<p[i];
	}
	cout<<endl;
}
void dfs(int x){
	if(x==n){
		prt();
		return;
	}else{
		for(int i=1;i<=n;i++){
			if(!pd[i]){
				pd[i]=1;
				p[x]=i;
				dfs(x+1);
				pd[i]=0;
			}
		}
	}
}
int main(){
	cin>>n;
	dfs(0);
	return 0;
}
