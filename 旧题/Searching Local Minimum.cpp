#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

const int N = 100010;
const int INF = 0x3f3f3f3f;

int n, a[N];
int l, r, mid;

int main()
{
	cin >> n;
	
	l = 1, r = n;
//	a[0] = INF, a[n + 1] = INF;
	
//	for (int i = 1; i <= n; i ++ ) cin >> a[i];
	
	while (l < r)
	{
		mid = (l + r) >> 1;
		
		if (a[mid] == 0) 
		{
			printf("? %d\n", mid);
			fflush(stdout);
			scanf("%d", &a[mid]);
		}
		if (a[mid + 1] == 0)
		{
			printf("? %d\n", mid + 1);
			fflush(stdout);
			scanf("%d", &a[mid + 1]);
		}
		if (a[mid] < a[mid + 1])
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	
	printf("! %d\n", l);
	cout << endl;
	
	return 0;
}
