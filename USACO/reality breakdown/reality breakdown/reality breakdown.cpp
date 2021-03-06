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

using namespace std;

/*
struct trie {
	char c;
	map<char, vector<int>>ch;
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<trie>t(n);
	map<char, set<int>>pos;
	map<char, vector<int>>x;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		t[i]={ c,x };
		pos[c].insert(i);
	}
	for (int i = 0; i < n-1; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		t[x].ch[t[y].c].push_back(y);
		t[y].ch[t[x].c].push_back(x);
	}
	for (int i = 0; i < k; i++) {
		string s;
		cin >> s;
		if (s.length() == 1) {
			cout << pos[s[0]].size() << "\n";
			continue;
		}
		int ct = 0;
		for (auto it:pos[s[0]]) {
			queue<int>Q;
			Q.push(it);
			int p = 1;
			vector<bool>vis(n, false);
			vis[it] = true;
			while (p<s.length()) {
				vector<int>add;
				while (!Q.empty()) {
					if (p == s.length())break;
					int x = Q.front();
					Q.pop();
					for (auto it : t[x].ch[s[p]]) {
						if (!vis[it]) {
							vis[it] = true;
							add.push_back(it);
							if (p == s.length() - 1)ct++;
						}
					}
				}
				p++;
				for (int i = 0; i < add.size(); i++) {
					Q.push(add[i]);
				}
			}
		}
		cout << ct << "\n";
	}
	return 0;
}*/

char node[20011];
vector<int> adj[20011];

