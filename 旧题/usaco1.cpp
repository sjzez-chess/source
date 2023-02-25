#include <bits/stdc++.h>
using namespace std;
int main(){
	long long  n;
	cin>>n;
	long long c[n];
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	sort(c,c+n);
	long long ans=0;
	long long anss;
	long long ansss;
	for(int k=0;k<n;k++){
		for(int h=0;h<n;h++){
			if(c[h]>=c[k]){
				ans=c[k]*(n-h);
				break;
			}
		}
		if(ans>anss){
			ansss=c[k];
			anss=ans;
		}
		ans=0;
	}
	cout<<anss<<" "<<ansss;
	return 0;
} 

