#include <bits/stdc++.h>
using namespace std;
long long m;
long long n;
long long ans;

/*void f(int r,int l,int score){
	int ret;
	int mid;
	while(l<r){
		mid=r+(l-r)/2;
		if(school[mid]==score){
			ans+=0;
			return;
		}
		if(school[mid]>score){
			r=mid;
		}
		if(school[mid]<score){
			l=mid;
		}
	}
	ans+=abs(school[l]-score);
	return;
}*/
int main(){	
	cin>>m>>n;
	long long school[m+1];
	long long score[n+1];
	for(int i=1;i<=m;i++){
		cin>>school[i];
	}
	sort(school+1,school+m+1);
	for(int i=1;i<=n;i++){
		cin>>score[i];
		long long lower=lower_bound(school+1,school+m+1,score[i])-school;
	//	int upper=upper_bound(school+1,school+m+1,score[i])-school;
	//	int up=abs(score[i]-school[upper]);
	//	int low=abs(score[i]-school[lower]);
		if(lower==m+1){
			ans+=score[i]-school[m];
			continue;
		}else if(lower==1){
			ans+=school[1]-score[i];
		}else{
			ans+=min(abs(school[lower]-score[i]),abs(score[i]-school[lower-1]));
		}
	}
	cout<<ans;
	
	return 0;
}
