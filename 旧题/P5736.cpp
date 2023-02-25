#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]==1){
			cout<<"1"<<" ";
		}
		else if(a[i]==2){
			cout<<"2"<<" ";
		}
		else if(a[i]==3){
			cout<<"3"<<" ";
		}else{
			for(int j=2;j<=sqrt(a[i]);j++){
				if(a[i]%j==0){
					a[i]=0;
					break;
				}	
			}
			if(a[i]>0){
				cout<<a[i]<<" ";
			}
		}
	}
	return 0;
}
