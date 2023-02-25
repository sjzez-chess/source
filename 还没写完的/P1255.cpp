#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
int f[10086];
int dp(int n){
	if(n==0){
		return 0;
	}
	if(f[n]){
		return f[n];
	}
	for(int i=3;i<=n;i++){
		ans=max(dp(n-1),dp(n-2));
	}
}
int main(){
	f[1]=1;
	f[2]=2;
	cin>>n;
	cout<<dp(n);
	return 0;
}
