#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cstdlib> 
#include <stack>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
int ans=0;
/*struct stu {
	int a;
	int b;
};
bool comp(stu aa,stu bb){
		return aa.b>bb.b;
}*/
struct cmp {
  bool operator()(int a, int b) { return a < b; }
};
map<int,int,cmp> s;
map<int,int>::iterator it;
int main(){
	int n;
	cin>>n;
	int t[n+1];
	for(int i=1;i<=n;i++){
		cin>>t[i];
		ans+=t[i];
		s[t[i]]=i;
	}
	for(it=s.begin();it!=s.end();it++){
		pair<int,int> p=*it;
		cout<<p.second<<" ";
	}
	cout<<endl<<fixed<<setprecision(2)<<float(ans/n);
	return 0;
}
