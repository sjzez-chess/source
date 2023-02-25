#include <bits/stdc++.h>
using namespace std;
struct mon{
	double m,v,val;
};

inline bool cmp(mon a,mon b){
	return a.val>b.val;
}
int n,t;
double ans;
int main(){
	cin>>n>>t;
	mon a[n];
	for(int i=0;i<n;i++){
		cin>>a[i].m>>a[i].v;
		a[i].val=a[i].v/a[i].m;
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		if(t>a[i].m){
			t-=a[i].m;
			ans+=a[i].v;
		}
		else{
			ans+=t*a[i].val;
			break;
		}
	} 
	cout<<fixed<<setprecision(2)<<ans;
	return 0;
} 
