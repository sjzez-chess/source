#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e9 + 10;

int n, m;
int c[25];
int b[2*maxn][25];  
int a[maxn];

inline int read()
{
	int x = 0, f = 1;char ch = getchar();
	while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x * 10 + ch - 48;ch = getchar();}
	return x * f;
}
/*
int fast(int v){
	int result = 1;
	int base = 2;
	while (v){
		if(v & 1){
			result = result * base % maxn;
		}
		power >> = 1;
		base = (base * base) % maxn;
  	}
	return result;
}
*/
void readd(){
	n = read();
	m = read();
	for(int i = 1; i <= n; i ++ ){
		a[i] = read();
		b[i][0] = a[i];
	} 
}

void STpre(){
	c[0] = 1;
	for(int i = 1; i <= 24; i ++ ){
		c[i] = c[i - 1] * 2;
	}
	int k = (int)log2(n);
	for(int j = 1; j <= k; j ++ ){
		for(int i = 1; i <= n; i ++ ){
			b[i][j] = max(b[i][j - 1], b[i + c[j - 1]][j - 1]);
		}
	}
}

void shuchu(){
	int r, l, k2;
	for(int h = 1, l, r, k2; h <= m; h ++ ){
		l = read();
		r = read();
		k2 = (int)log2(r - l + 1);
		cout << max(b[l][k2], b[r - c[k2] + 1][k2]) << endl;
	}
}

int main(){
		readd();
		
		STpre();
		
		shuchu();
		
	return 0;
}/*
#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e5+10;
int a[N];
int b[2*N][25];
int c[25];
//getchar()±Èscanf¿ì
int read(){
        int s,x;
        x=0;
        s=1;
        char c;
        c=getchar();
        while(c<'0' || c>'9'){
                if(c=='-'){
                        s=-1;
                }
                c=getchar();
        }
        while(c>='0' && c<='9'){
                x=x*10+(c-'0');
                c=getchar();
        }
        return s*x;

}
void init(){
        n=read(),m=read();
        for(int i=1;i<=n;i++){
                a[i]=read();
        }
}
void pre(){
        c[0]=1;
        for(int i=1;i<=20;i++){
                c[i]=c[i-1]*2;
        }
        for(int i=1;i<=n;i++){
                b[i][0]=a[i];
        }
        int mj=(int)log2(n);
        for(int j=1;j<=mj;j++){
                for(int i=1;i<=n;i++){
                        b[i][j]=max(b[i][j-1],b[i+c[j-1]][j-1]);
                }
        }
}
void work(){
        for(int i=1,l,r,k;i<=m;i++){
                l=read();
                r=read();
                k=int(log2(r-l+1));
                printf("%d\n",max(b[l][k],b[r-c[k]+1][k]));
        }
}
int main(){
        init();
        pre();
        work();
        return 0;
}
