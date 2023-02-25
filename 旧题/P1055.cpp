#include <bits/stdc++.h>
using namespace std;
int main(){
	string s="0123456789X";
	char ISBN[14];
	int j=1;
	int ans=0;
	for(int i=0;i<=12;i++){
		cin>>ISBN[i];
	}
	for(int i=0;i<=11;i++){
		if(ISBN[i]!='-'){
			ans+=(ISBN[i]-'0')*j++;
		}else{
			continue;
		}
	} 
	
	//ans=int(ISBN[1])*1+int(ISBN[3])*2+int(ISBN[4])*3+int(ISBN[5])*4+int(ISBN[7])*5+int(ISBN[8])*6+int(ISBN[9])*7+int(ISBN[10])*8+int(ISBN[11])*9;
	ans%=11;
	if(ans==ISBN[12]-'0'){
		cout<<"Right";	
	}else{
		ISBN[12]=s[ans];
		for(int i=0;i<=12;i++){
			cout<<ISBN[i];
		}
	}
	return 0;
} 
