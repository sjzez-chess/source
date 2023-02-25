#include <bits/stdc++.h>
/*#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cstdlib> 
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>*/
using namespace std;
const long long maxn=100086;
/*bool cmp(int a,int b){
	return a>b;
}*/
int main(){
	long long ji=-1;
	long long  n;
	cin>>n;
	long long c[n];
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	long long ans=0;
	long long anss=0;
	long long ansss=0;
	for(int j=1;;j++){
		for(int h=0;h<n;h++){
			if(c[h]>=j){
				ans+=j;
			}
		}
		if(ans==0){
			cout<<anss<<" "<<ansss;
			return 0;
		}
		if(ans>=anss){
			//ji++;
			if(ans>anss){
				ansss=j;
			}
			anss=ans;
		}
		ans=0;
	}
/*	sort(ansss,ansss+ji);
	cout<<anss<<" "<<ansss[ji];*/
	return 0;
} 
