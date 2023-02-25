#include <bits/stdc++.h>
using namespace std;
int a[10+1];
int erfen(int l,int r,int n){
	int ret=0;
	int mid;
	while(l<r){
		mid=(l+r+1)/2;
		if(a[mid]>n){
			r=mid;
		}
		if(a[mid]<n){
			l=mid+1;
		}
		if(a[mid]==n){
			return mid;
		}
	}
	if(a[l]<=n){
		return l;
	}else{
		return 0;
	}
}
int main(){
	for(int i=1;i<=10;i++){
		cin>>a[i];
	}
	sort(a+1,a+11);
	int height;
	cin>>height;
	height+=30;
	cout<<erfen(1,10,height);
}
