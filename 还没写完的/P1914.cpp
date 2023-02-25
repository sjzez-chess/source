#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string aaa="abcdefghijklmnopqrstuvwxyz";
	string mima;
	getline(cin,mima);
	getline(cin,mima);
	int a=mima.size();
	for(int i=0;i<a;i++){
		int ans;
		for(int j=0;j<26;j++){
			if(aaa[j]==mima[i]){
				ans=j;
			}
		}
		cout<<aaa[(ans+n)%a];
	}
	return 0;
}
