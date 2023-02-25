#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r)
{
	if(l >= r) return;//判断边界 
	
	int x = q[l],i = l - 1,j = r + 1;//至于为什么要++和-- ，因为先执行再判断 
	while(i < j)
	{
		do i ++ ; while(q[i] < x);
		do j -- ; while(q[i] > x);
		if(i < j) swap(q[i], q[j]);//两者交换各取所需 
	}
	
	quick_sort(q, l, j);//递归处理左右两边 
	quick_sort(q, j + 1, r);
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i ++ ) cin >> q[i];
	
	//quick_sort(q, 1, n);
	
    sort(q + 1,q + n + 1);

	for(int i = 1; i <= n; i ++ ) cout << q[i] << " "; 
	
	return 0;
}