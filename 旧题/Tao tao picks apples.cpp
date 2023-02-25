#include <bits/stdc++.h>
using namespace std;
int erfen(int a[],int hei,int n){
	
	int mid;
	int l=a[0];
	while(l<n){
		mid=(l+n)/2;
		if(a[mid]>=hei){
			n=mid;
		}
		/*if(a[mid]=hei){
			return mid;
		}*/
		if(a[mid]<hei){
			l=mid+1;
		}
	}
	if(a[l]<=hei) {
		return l;
	}else{
		return a[0];
	}
	
}
int main(){
	int n=10;
	int a[11];
	a[0]=0;
	int height;
	for(int i=1;i<=10;i++){
		cin>>a[i];
	}
	cin>>height;
	height+=30;
	sort(a,a+11);
	/*for(int i=0;i<11;i++){
		cout<<a[i]<<endl;
	}
	return 0;*/
	cout<<erfen(a,height,n);
	return 0;
}
