#include <bits/stdc++.h>
using namespace std;
int n;	
long long dp[10000][10000];
int main(){
	cin>>n;
	int p1[n+1];
	int p2[n+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			if(p1[i]==p2[j]){
			dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
		}
	}
}
	cout<<dp[n][n];
	return 0;
}
