#include <bits/stdc++.h>
using namespace std;
long long h;//锯片的最高高度 
long long m,n;//M是需要木材的总数量，N是树木的数量
long long tr[10000086];
bool check(long long tolly){
	long long ans=0;
	for(long long j=1;j<=n;j++){
		if(tr[j]>tolly){
			ans+=tr[j]-tolly;
		}
	}
	return m<=ans;
}
int ef(){
	long long mid;
	long long l=1;
	long long r=1e9;
	while(l<r){
		mid=(r+l+1)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	return l;
}
int main(){
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>tr[i];
	}
	//sort(tr+1,tr+n+1);
	long long nnn=ef();
	cout<<nnn;
}
