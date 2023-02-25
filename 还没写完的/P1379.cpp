#include <bits/stdc++.h>
using namespace std;
struct stt{
	string mx;//整条字符串的排列 
	int dep;//现在的栈数 
	int zeroid;//'0'的位置 
};
queue<stt> qu;//队列，整一个stt类型的
set<string> st;//用来存储字符串，看看是否访问过这个形式的字符串
void dup(stt s_t,char dir){
	int i,j;
	i=s_t.zeroid/3;
	j=s_t.zeroid%3;
	int ii,jj;
	ii=i,jj=j;
	switch(dir){
		case 'u':
			ii=i-1;
			break;
		case 'd':
			ii=i+1;
			break;
		case 'l':
			jj=j-1;
			break;
		case 'r':
			jj=j+1;
			break;
	}
	if(ii<0||ii>=3||jj<0||jj>=3){
		return;
	} 
	stt stt2=s_t;
        stt2.dep=s_t.dep+1;
        stt2.zeroid=ii*3+jj;
        swap(stt2.mx[stt2.zeroid],stt2.mx[s_t.zeroid]);
        if(st.count(stt2.mx)==0){
                st.insert(stt2.mx);
                qu.push(stt2);
        }
}
void bfs(){
	while(qu.empty()!=true){
		stt s_t=qu.front();
		qu.pop();
		if(s_t.mx=="123804765"){
			cout<<s_t.dep<<endl;//判定是不是和指定数组相同，如果相同就输出当前的栈数 
			return;
		}
		dup(s_t,'u');//向上交换 
		dup(s_t,'d');//向下交换 
		dup(s_t,'l');//向左交换 
		dup(s_t,'r');//向右交换 
	}
} 
int main(){
	string str;
	cin>>str;
	int zeroid;//用在下面找位置 
	int sz=str.size();
	for(int i=0;i<sz;i++){
		if(str[i]=='0'){
			zeroid=i;//找到0的位置，对zeroid进行初始化 
			break;
		}
	}
	qu.push({str,0,zeroid});//队列的初始化
	st.insert(str);//存入当前初始的字符串
	bfs();//调用函数 
	return 0;
}
