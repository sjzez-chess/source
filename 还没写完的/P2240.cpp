#include <bits/stdc++.h>
using namespace std;
	int n,t;
	bool cmp(int a,int b){
		return a>b;
	}
	double ans;
int main(){
	int tt=0;
	cin>>n>>t;
	int m[n],v[n];
	double val[n];
	for(int i=0;i<n;i++){
		cin>>m[i]>>v[i];
		val[i]=v[i]/m[i];
	}
	sort(val,val+n,cmp);
	for(int i=0;i<n;i++){
		if(t-tt>0){
			if(t-tt<=m[i]){
				ans+=(t-tt)*val[i]; 
				break;
			}else{
				ans+=v[i];
				tt+=m[i];
			}
		}
	} 
	cout<<fixed<<setprecision(2)<<ans;
	return 0;
} 
