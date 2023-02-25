#include <bits/stdc++.h>

using namespace std;

int main()
{
	char str[100];
	
	gets(str); // 输入字符串 
	
	int n = strlen(str);
	
	for (int i = 0; i < n; i ++ ) // 双指针输出单词 
	{
		int j = i;
		while (j < n && str[j] != ' ') j ++ ; //遇到空格或者到头就停下了 
		
		for (int k = i; k < j; k ++ ) cout << str[k];
		cout << endl;
		
		i = j; // 更新i的位置 
	}
	
	return 0;
}
