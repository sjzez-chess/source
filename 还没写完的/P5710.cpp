#include <bits/stdc++.h>
using namespace std;
int main(){
	int x;
	cin>>x;
	if(x>4&&x<=12&&x%2==0){
		cout<<1<<" ";
	}else{
		cout<<0<<" ";
	}
	if((x>4&&x<=12)||x%2==0){
		cout<<1<<" ";
	}else{
		cout<<0<<" ";
	}
	if(((x>4&&x<=12)&&x%2!=0)||((x<=4||x>12)&&x%2==0)){
		cout<<1<<" ";
	}else{
		cout<<0<<" ";
	}
	if((x<=4||x>12)&&x%2!=0){
		cout<<1<<" ";
	}else{
		cout<<0<<" ";
	}
	return 0;
}
