#include <bits/stdc++.h>
using namespace std;
struct stt{
	string mx;//�����ַ��������� 
	int dep;//���ڵ�ջ�� 
	int zeroid;//'0'��λ�� 
};
queue<stt> qu;//���У���һ��stt���͵�
set<string> st;//�����洢�ַ����������Ƿ���ʹ������ʽ���ַ���
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
			cout<<s_t.dep<<endl;//�ж��ǲ��Ǻ�ָ��������ͬ�������ͬ�������ǰ��ջ�� 
			return;
		}
		dup(s_t,'u');//���Ͻ��� 
		dup(s_t,'d');//���½��� 
		dup(s_t,'l');//���󽻻� 
		dup(s_t,'r');//���ҽ��� 
	}
} 
int main(){
	string str;
	cin>>str;
	int zeroid;//����������λ�� 
	int sz=str.size();
	for(int i=0;i<sz;i++){
		if(str[i]=='0'){
			zeroid=i;//�ҵ�0��λ�ã���zeroid���г�ʼ�� 
			break;
		}
	}
	qu.push({str,0,zeroid});//���еĳ�ʼ��
	st.insert(str);//���뵱ǰ��ʼ���ַ���
	bfs();//���ú��� 
	return 0;
}
