#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r)
{
	if(l >= r) return;//�жϱ߽� 
	
	int x = q[l],i = l - 1,j = r + 1;//����ΪʲôҪ++��-- ����Ϊ��ִ�����ж� 
	while(i < j)
	{
		do i ++ ; while(q[i] < x);
		do j -- ; while(q[i] > x);
		if(i < j) swap(q[i], q[j]);//���߽�����ȡ���� 
	}
	
	quick_sort(q, l, j);//�ݹ鴦���������� 
	quick_sort(q, j + 1, r);
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i ++ ) cin >> q[i];
	
	quick_sort(q, 1, n);
	
	for(int i = 0; i < n; i ++ ) cout << q[i]; 
	
	return 0;
}
