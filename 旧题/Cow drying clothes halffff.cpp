#include <bits/stdc++.h>
using namespace std;
int ans=0;
int sunc(int a,int b,int w[],int &r,int &l){
	int rr=r;                          /*�ҳ�ʪ��С�ڵ���a��λ��mid��
												����˵��ƶ���mid+1��Ȼ��l��rλ�õ�ֵ����ȥa*/
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
	/*����ans+1*/ 
		return ans+1;
}
int suunc(int a,int b,int w[],int &r,int &l){
	int rr=r;                          /*�ҳ�ʪ��С�ڵ���a��λ��mid��
												����˵��ƶ���mid+1��Ȼ��l��rλ�õ�ֵ����ȥa*/
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
bool check(int w[],int &n){		/*����ǲ��Ƕ�ɹ����*/ 
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
		int gg=sunc( a,b,w,r,l)+gg;/*����ѭ���������������ķ���ֵ�����ж��������ɹ���ˣ��ͷ���ʱ��*/ 
		/*if(w[n]<=0) {*//*�����ʪ���·�ɹ���ˣ��ǾͰѻ��Ӹ���һ����*/ 
		/*	n--;
			r--;
		}*/
		int aiyou=suunc(a,b,w,r,l);
		if(aiyou) {
			w[aiyou]-=b;
		}
		w[n]-=b;/*�濾������ʪ������*/ 
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









