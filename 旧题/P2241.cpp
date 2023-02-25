#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,m;       /*答案为Min(i,j).正方形*/ 
	cin>>n>>m;
	long long sum_zheng=0,sum_ju=0;
	for(int i=1;i<=n;i++){/*枚举右下角，计算此时答案，求和即可*/
	 	for(int j=1;j<=m;j++){
	 		sum_zheng+=min(i,j);
	 		sum_ju+=i*j-min(i,j);
		 }
	}
	cout<<sum_zheng<<" "<<sum_ju;
	return 0;
} 
