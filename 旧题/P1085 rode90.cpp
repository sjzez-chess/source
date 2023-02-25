#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct timer{
	ll school;
	ll home;
};
long long jj;
ll ans[7];
timer ji;
timer le[7];
int main(){
	for(int i=0;i<7;i++){
		cin>>le[i].home;
		cin>>le[i].school;
		if(le[i].home+le[i].school>=8){
			ans[i]=le[i].home+le[i].school;
		}else{
			ans[i]=0;
		}
	}
	for(int i=0;i<7;i++){
		if(ans[i]>ji.home){
			jj++;
			ji.home=ans[i];
			ji.school=++i;
		}
	}
	if(jj==0){
		cout<<"0";
		return 0;
	}
	cout<<ji.school;
	return 0;
}
