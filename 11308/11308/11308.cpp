#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#pragma warning(disable:4996)

#define INF 10000000000
#define MOD 1000000007
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
//#define int long long
	int t;
	cin >> t;
	while (t--) {
		string line;
		getline(cin, line);
		getline(cin, line);
		for (int i = 0; i < line.length(); i++) {
			line[i] = toupper(line[i]);
		}
		cout << line << "\n";
		int m, n, b;
		cin >> m >> n >> b;
		map<string, int>cost;
		for (int i = 0; i < m; i++) {
			string s;
			int x;
			cin >> s >> x;
			cost[s] = x;
		}
		vector<pair<int, string>>ret;
		for (int i = 0; i < n; i++) {
			int curr = 0;
			string out;
			getline(cin, out);
			getline(cin, out);
			int k;
			cin >> k;
			for (int j = 0; j < k; j++) {
				string s;
				int x;
				cin >> s >> x;
				curr += cost[s] * x;
			}
			if (curr <= b)ret.push_back({ curr,out });
		}
		sort(ret.begin(), ret.end());
		if (ret.size() == 0)cout << "Too expensive!\n";
		else {
			for (auto it : ret)cout << it.second << "\n";
		}
		cout << "\n";
	}
	return 0;
}