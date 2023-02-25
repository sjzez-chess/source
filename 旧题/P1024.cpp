#include <bits/stdc++.h>
using namespace std;
double a,b,c,d;
double CNM(double x){
	return a*pow(x,3)+b*pow(x,2)+c*x+d;
}
void f(double l,double r){
	double left=CNM(l);
	double right=CNM(r);
	if(r-l<=0.001){
		cout<<fixed<<setprecision(2)<<l<<" ";
		return;
	}
	double mid=l+(r-l)/2;
	double r_t=CNM(mid)*right;
	double l_t=CNM(mid)*left;
	if(CNM(mid)==0){
		cout<<fixed<<setprecision(2)<<mid<<" ";
	}
	if(right==0){
		cout<<fixed<<setprecision(2)<<r<<" ";
	}
	/*if(right==0){
		cout<<fixed<<setprecision(2)<<r<<" ";
	}*/
	if(l_t<0){
		f(l,mid);
	}
	if(r_t<0){
		f(mid,r);
	}

}
int main(){
	
	cin>>a>>b>>c>>d;
	for(double i=-100;i<=99;i++){
		if(CNM(i)*CNM(i+1.0)<=0){
			f(i,i+1.0);
		}
	}
	return 0;
} 
