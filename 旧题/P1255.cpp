#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
int dp(int n){
	if(n==1){
		return 1;
	}
	if(n==2){
		return 2;
	}
	for(int i=3;i<=n;i++){
		ans=max(dp(n-1),dp(n-2));
	}
}
int main(){
	
	cin>>n;
	cout<<dp(n);
	return 0;
}
