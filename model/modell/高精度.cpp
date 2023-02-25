#include <bits/stdc++.h>
using namespace std;
const int n=500+10;
const int N=10086+10;
int a[n];
int b[n];
int c[n];
//int ji;
//int a[N],b[N],c[N];
//int check;
void read(int a[]){
	string s;
	cin>>s;
	int ll=s.size();
	for(int i=ll-1;i>=0;i--){
		a[i]=s[ll-1-i]-'0';
	}
}
/*==============高精度假发===========*/
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
/*==============高精度剑法============
void jian_check(int a[],int b[]){
	for(int i=N-3;i>=0;i--){
		if(a[i]<b[i]){
			cout<<"-";
			check=-1;
			break;
		}else if(a[i]>b[i]){
			check=1;
			break;
		}
	}
}
void jian_run(int a[],int b[],int c[]){
	for(int i=0;i<=N-4;i++){
		if(a[i]<b[i]){
			a[i]+=10;
			a[i+1]-=1;
		}
		c[i]+=a[i]-b[i];
	}
}
void jian_prt(int c[]){
	int i=N-3;
	while(c[i]==0){
		i--;
	}
	while(i>=0){
		cout<<c[i];
		i--;
	}
	cout<<endl;
}*/
/*==================高精度惩罚================
//算法：a*b(i)*10^i
string stra,strb;
const int N=4000+10;
int a[N],b[N],c[N];
void read(string str,int a[]){
        int sz=str.size();
        for(int i=0;i<=sz-1;i++){
                a[i]=str[sz-1-i]-'0';
        }
}
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
void prt(int c[]){
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
}*/

/*==================高精度处罚================*/ 
string a,c;
long long b,i,d;
int main(){
read(a);
read(b);
	add(a,b,c);
	add_prt(c);
		/*jian_check(a,b);
		if(check==0){
			cout<<"0"<<endl;
			return 0;
		}
		if(check==-1){
			swap(a,b);
		}
		jian_run(a,b,c);
		jian_prt(c);*/
			/*cin>>stra;
       		cin>>strb;
     		read(stra,a);
        	read(strb,b);
        	mul(a,b,c);
        	prt(c);*/
				/*cin>>a>>b;   //神奇的读入
    			for (;i<a.length();i++)a[i]-=48;   //字符串转数字
    			for (i=0;i<a.length();i++)
   			    c.push_back((d*10+a[i])/b+48),d=(d*10+a[i])%b;  //模拟竖式
    			for (i=0;c[0]==48;i++)c.erase(c.begin(),c.begin()+1);   //去0
    			cout<<c;   //华丽的输出*/
	return 0;
}
