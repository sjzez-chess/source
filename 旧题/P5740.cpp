#include <bits/stdc++.h>
using namespace std;
struct stu{
	string name;
	int c,s,e,z;
};
int main(){
	int n;
	cin>>n;
	stu aa[n];
	int ans=0;
	int ji=0;
	for(int i=0;i<n;i++){
		cin>>aa[i].name;
		cin>>aa[i].c>>aa[i].s>>aa[i].e;
		if(aa[i].c+aa[i].s+aa[i].e>ans){
			ans=aa[i].c+aa[i].s+aa[i].e;
			ji=i;
		}
	}
	cout<<aa[ji].name<<" "<<aa[ji].c<<" "<<aa[ji].s<<" "<<aa[ji].e;
	return 0;
}
