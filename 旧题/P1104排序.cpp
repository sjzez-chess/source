#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n;
struct oier{
	string name;
	int year;
	int month;
	int day;
	int turn;
};
bool cmp(oier a,oier b){
	if(a.year!=b.year){
		return a.year<b.year;
	}else{
		if(a.month!=b.month){
			return a.month<b.month;
		}
		else if(a.month==b.month&&a.day==b.day){
			return a.turn>b.turn;
		}
		else if(a.day!=b.day){
			return a.day<b.day;
		} 
	}
}
int main(){
	int n;
	n=read();
	oier a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i].name>>a[i].year>>a[i].month>>a[i].day;
		a[i].turn=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i].name<<endl; 
	} 
	return 0;
}
