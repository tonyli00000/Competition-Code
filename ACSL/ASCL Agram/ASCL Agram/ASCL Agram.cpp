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

map<char, int>fc;
map<int, char>rev;
bool myfunction(pair<int,char> i, pair<int,char> j) { return (i.first<j.first); }
int main()
{
	fc['T'] = 10;
	fc['J'] = 11;
	fc['Q'] = 12;
	fc['K'] = 13;
	fc['A'] = 1;
	rev[10] = 'T';
	rev[11] = 'J';
	rev[12] = 'Q';
	rev[13] = 'K';
	rev[1] = 'A';
	int i, j, k;
	for (k = 0; k < 5; k++) {
		char a, b;
		cin >> a >> b;
		if (fc.find(a) != fc.end())a = fc[a];
		else a -= '0';
		map<char, set<int>>suit;
		vector<pair<int, char>>rank;
		for (i = 0; i < 5; i++) {
			char x, y;
			cin >> x >> y;
			if (fc.find(x) != fc.end()) {
				suit[y].insert(fc[x]);
				rank.push_back(make_pair(fc[x], y));
			}
			else {
				suit[y].insert(x - '0');
				rank.push_back(make_pair(x - '0', y));
			}
		}
		sort(rank.begin(), rank.end(), myfunction);
		auto it = suit.find(b);
		if (it != suit.end()) {
			bool found = false;
			set<int>temp = it->second;
			for (auto jt = temp.begin(); jt != temp.end(); jt++) {
				if (*jt > a) {
					if (rev.find(*jt)!=rev.end())cout << rev[*jt] << b << "\n";
					else cout << *jt << b << "\n";
					found = true;
					break;
				}
			}
			if (!found) {
				if (rev.find(*it->second.begin()) != rev.end())cout << rev[*it->second.begin()] << b << "\n";
				else cout << *it->second.begin() << b << "\n";
			}
		}
		else {
			if (rank[0].first==1||rank[0].first>9)cout << rev[rank[0].first] << rank[0].second << "\n";
			else cout << rank[0].first << rank[0].second << "\n";
		}
	}
    return 0;
}

