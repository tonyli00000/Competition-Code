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

using namespace std;

int main()
{
	int t, i, j, k;
	cin >> t;
	for (k = 0; k<t; k++) {
		int n;
		cin >> n;
		int min = 3000;
		vector<int>a;
		string line;
		getline(cin, line);
		for (i = 0; i<n; i++) {
			getline(cin, line);
			stringstream ss(line);
			string s;
			ss << line;
			int ct = 0;
			while (ss >> s)ct++;
			if (ct<min) {
				a.clear();
				a.resize(1, i + 1);
				min = ct;
			}
			else {
				if (ct == min)a.resize(a.size() + 1, i + 1);
			}
		}
		for (i = 0; i<a.size() - 1; i++)cout << a[i] << " ";
		cout << a[a.size() - 1] << "\n";
	}
	return 0;
}
