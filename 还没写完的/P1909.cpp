#include<cmath>
#include<cstdio>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;
int n,a,b,c,ans=2100000000,x;
int main(){
    cin>>n;
    for (int i=1;i<=3;i++){
        cin>>a>>b;
        x=ceil(n*1.0/a)*b;
        ans=min(x,ans);
    }
    cout<<ans<<endl;
    return 0;
}
