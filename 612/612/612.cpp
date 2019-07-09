#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>

using namespace std;
vector<int> e;
bool d(int x, int y) {
	return(y > x);
}
int main()
{
	int t, i, j, k;
	map<char, int>letter;
	letter['A'] = 0;
	letter['C'] = 1;
	letter['G'] = 2;
	letter['T'] = 3;
	cin >> t;
	for (k = 0; k < t; k++) {
		if (k != 0)cout << "\n";
		int m, n;
		cin >> m >> n;
		vector<string> s;
		char c;
		vector<int> q[102];
		//int ans[55],dup[55];
		unordered_map<int, int>ans;
		string line;
		//int e[102];
		for (i = 0; i < n; i++) {
			line = "";
			for (j = 0; j < m; j++) {
				cin >> c;
				q[i].push_back(letter[c]);
				line += c;
			}
			s.push_back(line);
			int ct = 0;
			for (j = m - 1; j >= 0; j--) {
				for (int l = j; l < m; l++) {
					if (q[i][j]>q[i][l])ct++;
				}
			}
			e.push_back(ct);
			ans.insert(pair<int,int>(ct, i));
		}
		sort(e.begin(), e.end(), d);
		for (i = 0; i < n; i++) {
			cout << s[ans[e[i]]] << "\n";
			ans.erase(e[i]);
		}

	}
	return 0;
}