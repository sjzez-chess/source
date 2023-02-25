#include <bits/stdc++.h>
using namespace std;
void pic(int x,int y){
	for(int i=1;i<=y;i++){
		for(int j=1;j<=x;j++){
			if(i*j>=24){
				cout<<" "<<"";
			}
			if(i*j<24){
				cout<<"**"<<"";
			}
			
		}
		cout<<endl;
	}
}
int i=0;
double sha(double x){
	if(x>0){
		double a=log(x)/log(3);
		i++;
		if(i==2){
			return a;
		}
		return sha(a);
	}
	if(x<=0) {
		double b=2*x+2;
		i++;
		if(i==2){
			return b;
		}
		return sha(b);
	}
} 
int main(){
	jibadesaunbuchulaizoul!!!!!!!!!!!!!!!!!!!!!!!!!
	return 0;
}
