#include <bits/stdc++.h> 
using namespace std;
long long a[10000][1000];
long long vis[10000][1000];
long long dp[10000][1000];	
int r;
int f(int x,int y){
	 if(vis[x][y]){
	 	return 	dp[x][y];
	 }else{
	 	vis[x][y]=1;
	 }
	 if(x==r){
	 	return dp[x][y]=a[x][y];
	 }
	return dp[x][y]=a[x][y]+max(f(x+1,y),f(x+1,y+1));
}
int main(){

	cin>>r;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=i;j++){
			cin>>a[i][j];
		}
	}
	int ans;
	ans=f(1,1); 
	cout<<ans;
	return 0;
}
