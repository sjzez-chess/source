#include <bits/stdc++.h>
using namespace std;
int main(){
	/*string k="sksooolla";
	cout<<k.find("s")<<endl;;*/
	int a[]={4,6,3,1,4};
	set<int> s(a,a+4);
//	s.erase();
	for(set<int>::iterator it=s.begin();it!=s.end();it++){
		cout<<*it<<endl;
	}
	cout<<s.max_size()<<endl;
	set<int>::iterator it=s.find(6);
	if(it==s.end()){
		cout<<"not find"<<endl;
	}	
	else cout<<"find"<<endl;
	cout<<s.count(4)<<endl;
	pair<set<int>::iterator,bool> p=s.insert(100);
	cout<<*(p.first)<<endl;
	cout<<p.second<<endl;
} 
