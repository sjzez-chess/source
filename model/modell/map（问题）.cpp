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
#include <string.h>
using namespace std;
struct student {
	int name;
	string score;
};
struct cmp {
	bool operator()(const student& a, const student& b) const {
		return a.score < b.score || (a.score == b.score && a.name > b.name);
	}
};
int main() {
	map<string, int, cmp> m;
		string name;
		int score;
	for (int i = 0; i <= 5; i++) {
	
		getline(cin, name);
		getline(cin, name);
	
		cin >> score;
		m.insert(make_pair(name, score));
	};
	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)

	{

		cout << (*it).first << endl;

		cout << (*it).second << endl;

	}
	return 0;
}
