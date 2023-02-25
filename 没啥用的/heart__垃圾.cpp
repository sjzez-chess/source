#include <bits/stdc++.h>
using namespace std;
void heart(int n,string s){
	int ss=s.size();
	int xi=0;
	int ji=1;
	int height=2*n;
	int wide=1+(n-1)*4;
   	int cen=n-1;
	for(int i=0;i<n-1;i++){
		for(int ii=0;ii<cen;ii++){
			for(int w=0;w<ss;w++)
				cout<<" ";
		}
		for(int ge=0;ge<ji;ge++){
		/*	if(i==0||i==1) break;*/
			cout<<s;
		}
		for(int iii=0;iii<cen-1;iii++){
			for(int gg=0;gg<ss;gg++)
				cout<<" ";
		}
		for(int ww=0;ww<ss;ww++)
			cout<<" ";
		for(int jjj=0;jjj<cen-1;jjj++){
			for(int oo=0;oo<ss;oo++)
				cout<<" ";
		}
		for(int gee=0;gee<ji;gee++){
		/*	if(i==0||i==1) break;*/
			cout<<s;
		}
		for(int jj=0;jj<cen;jj++){
			for(int hh=0;hh<ss;hh++)
				cout<<" ";
		}
		cen--;
		ji+=2;
		cout<<endl;
	}
	for(int y=0;y<2*n-1;y++){
		if(y==0){
			for(int ee=0;ee<ss;ee++){
			
				cout<<" ";
			}
			for(int tt=0;tt<wide-2*xi-2;tt++){
					cout<<s;
			}
			for(int qq=0;qq<ss;qq++)
				cout<<"      ";
			cout<<endl;
			xi++;
		} 
		else{
			for(int g=0;g<xi;g++){
				for(int rr=0;rr<ss;rr++)
					cout<<" ";
			}
			for(int u=0;u<wide-2*xi;u++){
				cout<<s;
			}
			for(int t=0;t<xi;t++){
				for(int q=0;q<ss;q++)
					cout<<" ";         
			}
			cout<<endl;
			xi++;
		}	
   }
}
int main(){
	int n;
	string s;
	getline(cin,s);
	cin>>n;
	heart(n,s);
	return 0;
}															  
