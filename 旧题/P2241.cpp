#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,m;       /*��ΪMin(i,j).������*/ 
	cin>>n>>m;
	long long sum_zheng=0,sum_ju=0;
	for(int i=1;i<=n;i++){/*ö�����½ǣ������ʱ�𰸣���ͼ���*/
	 	for(int j=1;j<=m;j++){
	 		sum_zheng+=min(i,j);
	 		sum_ju+=i*j-min(i,j);
		 }
	}
	cout<<sum_zheng<<" "<<sum_ju;
	return 0;
} 
