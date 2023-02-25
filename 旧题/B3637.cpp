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
	int d[5000+10];
	int ans=1;
int main(){
	for(int i=0;i<=5000;i++){
		d[i]=1;
	}
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i]>a[j]){
				d[i]=max(d[i],d[j]+1);
				ans=max(ans,d[i]);
			}
		}
	}
	cout<<ans;
	return 0;
}
