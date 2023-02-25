/*#include <bits/stdc++.h>
using namespace std;
int sq;
int n;
long long fn[10000][10000];
void f(int x1,int y1,int x2,int y2){
	if(x2-x1==1){
		return;
	}
	for(int i=x1;i<=(x2-x1)/2+1;i++){
		for(int j=y1;j<=(x2-x1)/2+1;j++)
		fn[i][j]=0;
	}
	f(x1+x2/2,y1,x2,y2);
	f(x1+(x2-x1)/2,(x2-x1)/2+y1,x2,(x2-x1)/2+y1);
	f(x1,(x2-x1)/2+y1,x2-(x2-x1)/2,(x2-x1)/2+y1);
}
int main(){
	
	int n;
	cin>>n;
	int sq=pow(2,n);
	for(int i=1;i<=sq;i++){
		for(int j=1;j<=sq;j++){
			fn[i][j]=1;
		}
	}
	f(1,1,sq,1);
	for(int i=1;i<=sq;i++){
		for(int j=1;j<=sq;j++){
			cout<<fn[i][j];
		}
		cout<<endl;
	}
	return 0;
}*/
#include<bits/stdc++.h>
#define MAXN 2005
#define reg register
#define inl inline
using namespace std;
int n;
bool ans[MAXN][MAXN];
void Dfs(reg int x,reg int y,reg int xx,reg int yy)
{
    if(x==xx && y==yy) return;
    reg int tx=(x+xx)/2,ty=(y+yy)/2;
    for(reg int i=x;i<=tx;i++)
    {
        for(reg int j=y;j<=ty;j++) ans[i][j]=1;
    }
    Dfs(x,ty+1,tx,yy);
    Dfs(tx+1,y,xx,ty);
    Dfs(tx+1,ty+1,xx,yy);
}
int main()
{
    reg int x;
    scanf("%d",&x);
    n=1<<x;
    Dfs(1,1,n,n);
    for(reg int i=1;i<=n;i++)
    {
        for(reg int j=1;j<=n;j++) printf("%d%c",ans[i][j]?0:1,j==n?'\n':' ');
    }
    return 0;
}
