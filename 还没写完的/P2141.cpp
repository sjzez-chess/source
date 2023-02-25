#include <bits/stdc++.h>
using namespace std;
int f[1000][1000];
set<int> op;
int main(){
	int ans=0;
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i!=j){
				f[i][j]=a[i]+a[j];
				int kk=f[i][j];
				op.insert(kk);
			}
		}
	}
	for(set<int>::iterator it=op.begin();it!=op.end();it++){
		for(int i=0;i<n;i++){
			if(*it==a[i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
