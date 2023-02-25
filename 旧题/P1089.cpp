#include <bits/stdc++.h>
using namespace std;
int rest[14];
int ans;
int main(){
	int yu[14];
	
	for(int i=1;i<=12;i++){
		cin>>yu[i];
	}
	for(int i=1;i<=12;i++){
		rest[i]=300-yu[i]+rest[i-1];
		if(rest[i]<=0){
			rest[i]=0;
		}
		ans+=(rest[i]/100)*100;
		rest[i]%=100;
		if(i==12){
			rest[12]+=ans*(1.2);
		}
	}
	cout<<rest[12];
	return 0;
}
