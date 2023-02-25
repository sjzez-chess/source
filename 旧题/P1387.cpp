#include <bits/stdc++.h>
using namespace std;
	int f[100+1][100+1];
	int ans;
int main(){
	int n,m;
	cin>>n>>m;
	int fang[n+1][m+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>fang[i][j];
			if(fang[i][j]==1) {
				f[i][j]=min(f[i-1][j],min(f[i][j-1],f[i-1][j-1]))+1;
				if(ans<f[i][j]){
					ans=f[i][j];
				}
			}
		}
	} 
	cout<<ans;
	return 0;
}
