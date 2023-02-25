#include <bits/stdc++.h>
using namespace std;
	int ans;
	int s[55];
int main(){
	int n;
	cin>>n;
	s[0]=1;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]*i;
		ans+=s[i];
	}
	cout<<ans;
	return 0;
}
