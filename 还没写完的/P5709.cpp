#include <bits/stdc++.h>
using namespace std;
int main(){
	int m,t,s;
	cin>>m>>t>>s;
	if(m==0){
		cout<<"0";
		return 0;
	}
	if(t==0){
		cout<<"0";
		return 0;
	}
	int a;
	a=m-ceil((double)s/t);
	if(a<=0){
		cout<<0;
	}else{
		cout<<a;
	}
	return 0;
}
