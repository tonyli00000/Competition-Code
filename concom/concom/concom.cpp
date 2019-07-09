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

int i, j, k;
int control[105][105];
bool controlled[105][105];
map<int, int>name,rev;
int main()
{
	int n;
	cin >> n;
	for (i = 0; i < 105; i++) {
		for (j = 0; j < 105; j++) {
			control[i][j] = 0;
			controlled[i][j] = false;
		}
	}
	int ct = 0;
	vector<vector<int>>company;
	company.resize(105);
	for (i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		control[x][y] += z;
		if (rev.find(x) == rev.end()) {
			ct++;
			name[ct] = x;
			rev[x] = ct;
		}
		company[x].push_back(y);
		if (rev.find(y) == rev.end()) {
			ct++;
			name[ct] = y;
			rev[y] = ct;
		}
		if (z >= 50)controlled[x][y] = true;
	}
	for (k = 1; k <= ct; k++) {
		for (i = 1; i <= ct; i++) {
			for (j = 1; j <= ct; j++) {
				if (controlled[name[i]][name[k]]) {
					control[name[i]][name[j]] += control[name[k]][name[j]];
					if (control[name[i]][name[j]]>50)controlled[name[i]][name[j]] = true;
				}
			}
		}
	}
	vector<pair<int, int>>out;
	for (i = 1; i <= ct; i++) {
		for (j = 1; j <= ct; j++) {
			if (i != j && controlled[name[i]][name[j]])out.push_back(make_pair(name[i], name[j]));
		}
	}
	sort(out.begin(), out.end());
	for (i = 0; i < out.size(); i++) {
		cout << out[i].first << " " << out[i].second << "\n";
	}

    return 0;
}

