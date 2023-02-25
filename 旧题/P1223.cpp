#include <bits/stdc++.h>
using namespace std;

long long n;
long long t[1000+20];
long long shu[1000+20];
double ret=0;
void f(long long a[],long long b[]){
	for(int i=1;i<=n;i++){
		for(int j=n;j>1;j--){
			if(a[j]<a[j-1]){
				swap(a[j],a[j-1]);
				swap(b[j],b[j-1]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<shu[i]<<" ";
	}
	cout<<endl;
	int ji=n;
	for(int i=1;i<=n;i++){
		ret+=a[i]*(n-i);
	}
	cout<<fixed<<setprecision(2)<<ret/n;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i];
		shu[i]=i;
	}
	f(t,shu);
	return 0;
}
