#include <bits/stdc++.h>

using namespace std;

int main()
{
	char str[100];
	
	gets(str); // �����ַ��� 
	
	int n = strlen(str);
	
	for (int i = 0; i < n; i ++ ) // ˫ָ��������� 
	{
		int j = i;
		while (j < n && str[j] != ' ') j ++ ; //�����ո���ߵ�ͷ��ͣ���� 
		
		for (int k = i; k < j; k ++ ) cout << str[k];
		cout << endl;
		
		i = j; // ����i��λ�� 
	}
	
	return 0;
}
