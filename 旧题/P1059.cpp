/*#include <bits/stdc++.h>
using namespace std;
	struct cmop{
		int num;
		int times;
	};
	struct cmp{
		bool operator()(const cmop& a, const cmop& b) const {
 	   	return a.num < b.num;
	  }
	};
	map<cmop,cmp> mm;
int main(){
    srand(time(0));                                               
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cmop x;
		x.num=rand()%100+1;
        mm[x.num]++;
    }
    int ans=0;
    map<int,int>::iterator it;
	for(it=mm.begin();it!=mm.end();it++){
        ans++;
    }
	cout<<ans<<endl;
    for(it=mm.begin();it!=mm.end();it++){
        cout<<(*it).first<<" ";
    }
    return 0;
}*/
#include <bits/stdc++.h>
using namespace std;
int main(){
    srand(time(0));                                               
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int b=unique(a,a+n)-a;
    cout<<b<<endl;
    for(int j=0;j<b;j++){
        cout<<a[j]<<" ";
    }
    return 0;
}
    
    
