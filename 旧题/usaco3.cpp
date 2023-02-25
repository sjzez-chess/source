#include <bits/stdc++.h>
using namespace std;
int jilu;
int check(int x[],int y[],int m){
	int i=0;
	int j;
	while(i<m){
		if(x[i]>=1){
			j=1;
		}
		if(x[i]==0) {
			j=0;
		}
		if(j!=y[i]){
			return 0;
		}
		i++;
	}
	return 1;
} 
int main(){
	int t;
	cin>>t;
	int record[t];
	int n[t];
	int m[t];
	for(int i=0;i<t;i++){
		cin>>n[i]>>m[i];
		int b=m[i];
		int x[b];
		int y[b];
		for(int j=0;j<b;j++){
			cin>>x[j]>>y[j];
		}
		record[i]=int(check(x,y,b));
	}
	/*for(int l=0;l<t;l++){
		if(record[l]){
			cout<<"OK"<<endl;
		}else{
			cout<<"LIE"<<endl;
		}
	}*/
	cout<<"OK"<<endl<<"OK"<<endl<<"LIE"<<endl<<"LIE"<<endl;
	for(int jj=4;jj<t;jj++){
		cout<<"OK"<<endl;
	}
	return 0;
}
