#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int t;
	cin >> t;
	int i, j, k;
	for (k = 0; k < t; k++) {
		map <string, int> hw;
		cout << "Case " << k + 1 << ": ";
		int m;
		string line;
		cin >> m;
		for (i = 0; i < m; i++) {
			int n;
			cin >> line;
			cin >> n;
			hw[line] = n;
		}
		cin >> m;
		cin >> line;
		if (hw.find(line) == hw.end() || hw[line]>m + 5)cout << "Do your own homework!\n";
		else {
			if (hw[line] > m)cout << "Late\n";
			else cout << "Yesss\n";
		}
	}
	return 0;
}
