#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,b;
	int ji=0;
	int ans=0;
	cin>>n>>b;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		if(ans>=b){
			break;
		}
		ans+=a[i];
		ji++;
	}
	cout<<ji;
	return 0;
}
