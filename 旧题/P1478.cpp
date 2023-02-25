#include <bits/stdc++.h>
using namespace std;

int n,a,s,b;


int main(){
	
	cin>>n>>s;
	cin>>a>>b;
	int strength[n+1];
	int height[n+1];
	int tall=a+b;
	int che=0;
	int h,ss;
	for(int i=1;i<=n;i++) {
		cin>>h>>ss;
		if(h<=tall){
			height[i]=h;
			strength[i]=ss;
		}else{
			strength[i]=1e9;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>1;j--){
			if(strength[j]<strength[j-1]){
				swap(strength[j],strength[j-1]);
			}
		}
	}
	//sort(strength+1,strength+che+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(s>=strength[i]){
			ans++;
			s-=strength[i];
		}
	} 
	cout<<ans;
	/*for(int i=1;i<=n;i++){
		cout<<strength[i]<<endl;
	}*/
	return 0;
}
