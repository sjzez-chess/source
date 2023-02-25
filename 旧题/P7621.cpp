#include <bits/stdc++.h>
using namespace std;
int main(){
	double ans=0;
	int n;
	cin>>n;
	int val[n];
	double count[n];
	for(int i=0;i<n;i++){
		cin>>val[i]>>count[i];
		val[i]*=0.85;
		ans+=val[i]*count[i];
	}
	cout<<fixed<<setprecision(1)<<ans;
	return 0;
}
