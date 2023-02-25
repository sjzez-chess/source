#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cstdlib> 
#include <stack>
#include <queue> 
#include <map>
#include <string>
#include <deque>
#include <vector>
using namespace std;
const long long MAXN = 100086;
int height[MAXN];
int erfen(int a[], int b, int n) {
	int end = n;
	int fir = 0;
	int ret = -2;
	int mid;
	while (a[fir] <= a[end - 1]) {
		mid = a[fir] + (a[end - 1] - a[fir])/ 2;
		if (mid >  b) {
			end = (end + 1) / 2;
		}
		else if (mid < b) {
			fir + = mid + 1;
		}
		else if (mid == b) {
			ret = mid;
		}
	}
	ret++;
	return ret;
}
int shu(int l,int r,int m){
	
}
int main() {
	int n, m;
	cin >> n >> m;
	int height[n];
	for(int i=0;i<n;i++){
		cin>>height[i];
	}
	
/*	int k[m];
	int a[n];
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
	int b[m];
	for (int j = 0; j < m; j++) {
		cin >> b[j];
	}
	for (int h = 0; h < m; h++) {
		k[h] = erfen(a, b[h], n);
	}
	for (int g = 0; g < m; g++) {
		cout << k[g] << " ";
	}*/
	
	return 0;
}
