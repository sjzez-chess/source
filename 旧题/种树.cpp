#include <bits/stdc++.h> 
using namespace std;
int main (){
	int ji=0;
	int l,m;
	cin>>l>>m;//���� 
	l++;//��ľ�������� 
	int ll[l];//���� 
	int a[m*2];//��Χ 
	for(int i=0;i<=l;i++){//��ÿ������ʼ��Ϊ1 
		ll[i]=1;}
	for(int h=0;h<=m*2-1;h++){//���뷶Χ 
		cin>>a[h];
	}
	for(int j=m*2-1;j>=0;j-=2){//����Χ�������� 
		if(a[j]>a[j-1]){//���У�����ֹ�������ʼ���ʱ�� 
			for(int hh=a[j];hh>=a[j-1];hh--){
				ll[hh]=0;//����ľֵ��Ϊ0 
			}
		}
		if(a[j]==a[j-1]) {//����ֹ�������ʼ���ʱ�� 
		ll[a[j]]=0;
		}
	}
	for(int y=0;y<=l-1;y++){ 
		if(ll[y]==1) ji++;//��δ��ֵ����ľ�ĸ�����¼���� 
	}
	cout<<ji;
	return 0;
} 
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      







