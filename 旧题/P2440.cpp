#include <bits/stdc++.h>
using namespace std;
const long long maxn=1e5+20;
int n,k;
int length[maxn];
bool check(long long m){
	long long ans=0;
	for(int i=1;i<=n;i++){
		int c=length[i]/m;
		ans+=c; 
	}
	if(ans>=k){
		return true;
	}
	if(ans<k){
		return false;
	}
}
long long f(int l,int r){
	int mid;
	while(l+1<r){
		mid=l+(r-l)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid;
		}
		
	}
	return l;
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>length[i];
	}
	int ret=f(0,100000001);
	cout<<ret;
	return 0;
}
