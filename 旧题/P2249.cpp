#include <bits/stdc++.h>
using namespace std;
int ret=-1;
int  find(int a[],int l,int r,int q,int n){
	int mid;
	while(l<r){
		int mid;
		mid=l+(r-l)/2;
		if(a[mid]>=q) {
			r=mid;
		}
		if(a[mid]<q){
			l=mid+1;
		}
	}
	if(a[l]==q) {
		return l;
	}else{
		return -1;
	}
	
}
int main(){
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b[m+1];
	for(int k=1;k<=m;k++){
		cin>>b[k];
	}
	for(int j=1;j<=m;j++){
		int q=b[j];
		int findd=find(a,1,n,q,n);
		cout<<findd<<" ";
	}
	return 0;
}
