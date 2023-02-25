#include <bits/stdc++.h>
using namespace std;
/*========================================================*/
string stra,strb;
const int N=4000;
int a[N],b[N],c[N];
/*==========================================================*/
void read(string str,int a[]){
        int sz=str.size();
        for(int i=0;i<=sz-1;i++){
                a[i]=str[sz-1-i]-'0';
        }
}
/*======================================================*/
void add(int a[],int b[],int c[]){
	for(int i=0;i<500;i++){
		c[i]+=a[i]+b[i];
		if(c[i]>=10){
			c[i+1]+=c[i]/10;
			c[i]=c[i]%10;
		}
	}
}
void add_prt(int c[]){
	int i=510;
	while(i>=0&&c[i]==0){
		i--;
	}
	if(i==-1){
		cout<<"0"<<endl;
		return ;
	}
	while(i>=0){
		cout<<c[i];
		i--;
	}
}
/*===================================================*/

void mul(int a[],int b[],int c[]){
        int sza=stra.size();
        int szb=strb.size();
        for(int i=0;i<szb;i++){
                for(int j=0;j<sza;j++){
                        c[i+j]+=b[i]*a[j];
                }
                for(int j=0;j<sza;j++){
                        c[i+j+1]+=c[i+j]/10;
                        c[i+j]=c[i+j]%10;
                }
        }
}
void prt_mul(int c[]){
        int i=N-3;
        while(i>=0 && c[i]==0){
                i--;
        }
        if(i==-1){
                cout<<0<<endl;
                return;
        }
        while(i>-1){
                cout<<c[i];
                i--;
        }
        cout<<endl;
}
/*=======================================================*/
	unsigned long long ans;
	unsigned long long s[55];
int main(){
	int n;
	cin>>n;
	s[0]=1;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]*i;
		ans+=s[i];
	}
	cout<<ans;
	return 0;
}
