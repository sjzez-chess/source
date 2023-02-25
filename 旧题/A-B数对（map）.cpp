#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100086];
map<int,int> ying;
int main(){
	ll ans=0;//¼ÆÊýÆ÷ 
	ll n,c;
	cin>>n>>c;
	ll a[n+1];
	a[0]=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		ying[a[i]]++;
		a[i]-=c;
	}
	//sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		ans+=ying[a[i]];
	}
	cout<<ans;
	return 0;
}
