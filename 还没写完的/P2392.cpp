#include <bits/stdc++.h>
using namespace std;
int s1,s2,s3,s4;
void read(int a[],int s){
	for(int i=1;i<=s;i++){
		cin>>a[i];
	}
}
bool check(int a[],int s){
	for(int i=1;i<=s;i++){
		if(a[i]){
			return false;
		}
	}
	return true;
}
int ans;
int main(){
	cin>>s1>>s2>>s3>>s4;
	int a[s1+1],b[s2+1],c[s3+1],d[s4+1];
	read(a,s1);
	read(b,s2);
	read(c,s3);
	read(d,s4);
	sort(b+1,a+1+s2);
	sort(a+1,a+1+s1);
	sort(c+1,a+1+s3);
	sort(d+1,a+1+s4);
	if(check(a,s1)){
		ans+=0;
	}else{
		if(s1%2==1){
			for(int i=s1;i>=1;i-=2){
				if(i==1){
					ans+=a[1];
					break;
				} 
				ans+=a[i];
			}
		}else{
			for(int i=s1;i>=2;i-=2){
				ans+=a[i];
			}
		}
	}
	if(check(b,s2)){
		ans+=0;
	}else{
		if(s2%2==1){
			for(int i=s2;i>=1;i-=2){
				if(i==1){
					ans+=b[1];
					break;
				} 
				ans+=b[i];
			}
		}else{
			for(int i=s2;i>=2;i-=2){
				ans+=b[i];
			}
		}
	}
	if(check(c,s3)){
		ans+=0;
	}else{
		if(s3%2==1){
			for(int i=s3;i>=1;i-=2){
				if(i==1){
					ans+=c[1];
					break;
				} 
				ans+=c[i];
			}
		}else{
			for(int i=s3;i>=2;i-=2){
				ans+=c[i];
			}
		}
	}
	if(check(d,s4)){
		ans+=0;
	}else{
		if(s4%2==1){
			for(int i=s4;i>=1;i-=2){
				if(i==1){
					ans+=d[1];
					break;
				} 
				ans+=d[i];
			}
		}else{
			for(int i=s4;i>=2;i-=2){
				ans+=d[i];
			}
		}
	}
	cout<<ans;
	return 0;
}
