#include <bits/stdc++.h>
using namespace std;
int main(){
	int k;
	cin>>k;
	int n=0;
	double S=0;
	for(int i=1;;i++){
		if(S<=k){
			S=S+1.0/i;
			n++;
			//cout<<S<<"  "<<n;
		}else{
			break;
		}
	}
	cout<<n;
	return 0;
}
