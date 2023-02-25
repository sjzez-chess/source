#include <bits/stdc++.h>
using namespace std;
const int MN=150+10;
char a[MN][MN];
int d[MN][MN];
int vis[MN][MN];
int c,r;
queue<pair<int,int> > qu;
pair<int,int> k,h;
int dx[]={-1,1,-2,2,-2,2,-1,1};
int dy[]={-2,-2,-1,-1,1,1,2,2};
void db_prt(){
        for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                        cout<<d[i][j]<<" ";
                }
                cout<<endl;
        }
}
void bfs(){
        qu.push(k);
        d[k.first][k.second]=0;
        vis[k.first][k.second]=true;
        while(!qu.empty()){
                pair<int,int> p;
                p=qu.front();
                if(p==h){
                        cout<<d[p.first][p.second]<<endl;
                        //db_prt();
                        return;
                }
                qu.pop();
                for(int i=0,nx,ny;i<8;i++){
                        nx=p.first+dx[i];
                        ny=p.second+dy[i];
                        if(nx>=r || nx<0 || ny<0 || ny>=c)
                                continue;
                        if((a[nx][ny]=='.' || a[nx][ny]=='H') && vis[nx][ny]==false){
                                qu.push(make_pair(nx,ny));
                                //vis[nx][ny]=true;
                                vis[nx][ny]=true;
                                d[nx][ny]=d[p.first][p.second]+1;
                        }
                }
        }
        //db_prt();
}
int main(){
        cin>>c>>r;
        for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                        cin>>a[i][j];
                        if(a[i][j]=='K'){
                                k=make_pair(i,j);
                        }else if(a[i][j]=='H'){
                                h=make_pair(i,j);
                        }
                }
        }
        bfs();

        return 0;
}

