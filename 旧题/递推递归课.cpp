#include <bits/stdc++.h>
using namespace std;
long long f[100000];
int ans=0;
long long ff(int x){
	if(x==1) return 1;
	if(x==2) return 2;
	if(x==3) return 4;
	return ff(x-1)+ff(x-2)+ff(x-3);
}
long long han(long long n){
	if(f[n]) return f[n];
	if(n==1) return 1;
	long long ans=han(n-1)+1+han(n-1);
	f[n]=ans;
	return ans;
}
long long op(long long x){
	 
}

int main(){
	/*long long n; 
	cin>>n;
	/*cout<<pp(n);*/
//	cout<<fixed<<setprecision(100)<<log10(101);
/*int day;
	double jin,tui;
	for(int i=1;i<=365;i++){
		if(pow(1.01,i)==100*pow(0.99,i)) day=i;
	}
	cout<<day;*/
	string s;
	getline(cin,s);
	cout<<s;
}
