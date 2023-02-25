#include <bits/stdc++.h>
using namespace std;
	set<int> s;
	set<int>::iterator r;
	set<int>::iterator l;
	int ans=0;
int aaa(int a,int b){
	return a+b;
}
char sa[100];
void aaa(){
	int j=0;
	for(int i=0;i<100;i++){
		cin>>sa[i];
		if(sa[i]=='0') break;
		j++;
	}
	for(int y=0;y<j;y++){
		cout<<sa[y];
	}
}
int main(){
aaa();
/*	int n;
	cin>>n;
	int a[n+1];
	cin>>a[0];
	s.insert(a[0]);
	ans+=a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		r=s.lower_bound(a[i]);
		if(r==s.end()) {
			ans+=abs(a[i]-*(--r));
			s.insert(a[i]);
			continue;
			}
		if(r!=s.begin()) {
			l=s.lower_bound(a[i]);
		}
		else{
			ans+=abs(a[i]-*r);
			s.insert(a[i]);
			continue;
		}
		ans+=min(abs(a[i]-*r),abs(a[i]-*l));
		s.insert(a[i]) ;
	}
	cout<<ans;*/
/*	int a[]={1,5,6,9,2,3};+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	set<int> s(a,a+6);
	r=s.end();
	cout<<*r<<endl;*/
/*	r=s.lower_bound(8);//找不小于8的最小数 
	cout<<*r<<endl;
	r=--s.lower_bound(8);//指向前一个位置 
	cout<<*r<<endl;
	r--;//指向前一个位置 
	cout<<*r<<endl;
	r--;//指向前一个位置 
	cout<<*r<<endl;
	r--;//指向前一个位置 
	cout<<*r<<endl;
	r--;//指向前一个位置 
	cout<<*r<<endl;
	r--;//指向前一个位置 
	cout<<*r<<endl;
	r--;//指向前一个位置 
	cout<<*r<<endl;
	r--;//指向前一个位置 
	cout<<*r<<endl;
	r--;//指向前一个位置 
	cout<<*r<<endl;
	r--;//指向前一个位置 
	cout<<*r<<endl;*/
	
	return 0;
} 
