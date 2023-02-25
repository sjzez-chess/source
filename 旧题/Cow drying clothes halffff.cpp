#include <bits/stdc++.h>
using namespace std;
int ans=0;
int sunc(int a,int b,int w[],int &r,int &l){
	int rr=r;                          /*找出湿度小于等于a的位置mid，
												将左端点移动到mid+1，然后将l到r位置的值都减去a*/
	int mid;
	while(r<l){
		mid=r+(l-r)/2;
		if(w[mid]>a){
			r=mid;
		}
		if(w[mid]<a){
			l=mid+1;
		}
	}
	
	for(int j=l;j<=rr;j++){
		w[j]-=a;
	}
	/*返回ans+1*/ 
		return ans+1;
}
int suunc(int a,int b,int w[],int &r,int &l){
	int rr=r;                          /*找出湿度小于等于a的位置mid，
												将左端点移动到mid+1，然后将l到r位置的值都减去a*/
	int mid;
	while(r<l){
		mid=r+(l-r)/2;
		if(w[mid]>a){
			r=mid;
		}
		if(w[mid]<a){
			l=mid+1;
		}
	}
	int ddddd=0;
	int ccccc=0;
	int aaa=0;
	int bbb=0;
	for(int j=l;j<=rr;j++){
		w[j]-=a;
		if(w[j]>0&&ddddd==0){
			ccccc=j;
			ddddd++;
		}
		if(w[j]==b&&aaa==0){
			aaa++;
			bbb=j;
		}
	}
	if(bbb!=0){
		return bbb;
	}else{
		return ccccc;
	}
}
bool check(int w[],int &n){		/*检查是不是都晒干了*/ 
	int add=0;
	for(int j=1;j<=n;j++){
		if(w[j]>0){
			add++;
		}
	}
	if(add>0) return false;
	else return true;
}
int suncc(int a,int b,int w[],int &r,int &l,int &n){
	int gg=0;
	for(int k=1;;k++){
		int gg=sunc( a,b,w,r,l)+gg;/*利用循环将上两个函数的返回值进行判定，如果都晒干了，就返回时间*/ 
		/*if(w[n]<=0) {*//*如果最湿的衣服晒干了，那就把机子给上一个用*/ 
		/*	n--;
			r--;
		}*/
		int aiyou=suunc(a,b,w,r,l);
		if(aiyou) {
			w[aiyou]-=b;
		}
		w[n]-=b;/*烘烤机给最湿的先用*/ 
		if(check(w,n)==true){
			return gg;
		}
	}
}
int main(){
	int n,a,b;
	cin>>n>>a>>b;
	int w[n+1];
	w[0]=0;
	for(int p=1;p<=n;p++){
		cin>>w[p];
	}
	int r=1;
	int l=n;
	int time=suncc(a,b,w,r,l,n);
	cout<<time;
	return 0;
}









