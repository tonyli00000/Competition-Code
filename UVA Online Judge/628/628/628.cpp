#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>

using namespace std;

int n, m;
string rule;
string dict[110], digits[] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

void generate(int v, string s) {
	if (v == rule.size()) {
		cout << s << "\n";
		return;
	}
	switch (rule[v]) {
	case '#':
		for (int i = 0; i < n; i++)
			generate(v + 1, s + dict[i]);
		break;
	case '0':
		for (int i = 0; i < 10; i++)
			generate(v + 1, s + digits[i]);
		break;
	}
}

int main() {
	while (cin>>n) {
		cout<<"--\n";
		for (int i = 0; i < n; i++)
			cin >> dict[i];
		cin >>m;
		for (int i = 0; i < m; i++) {
			cin >> rule;
			generate(0, "");
		}
	}
}