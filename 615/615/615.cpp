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

int p[1005], rk[1005];
int findset(int i) {
	return(p[i] == i) ? i : (p[i] = findset(p[i]));
}
void changeset(int m, int n) {
	if (p[m] != m)changeset(p[m], n);
	p[m] = n;
}
int convert(string s) {
	int i, m = 1, n = 0;
	for (i = s.length() - 1; i >= 0; i--) {
		n += m*(s[i] - '0');
		m *= 10;
	}
	return n;
}

void unionset(int x, int y) {
	p[y] = x;
}
int main()
{
	int m, n,tc=0;
	map<int, int>node;
	for (int i = 0; i <= 1000; i++) {
		p[i] = i;
		rk[i] = 0;
	}
	bool istree = true;
	while (cin >> m >> n) {
		if (m == -1 && n == -1)break;
		if (m == 0 && n == 0) {
			cout << "Case " << ++tc<<" ";
				int pre = findset(0),i;
			for (i = 1; i < node.size(); i++) {
				if (findset(i) != pre)break;
			}
			if (i==node.size())cout << "is a tree\n";
			else cout << "is not a tree\n";
			node.clear();
			for (int i = 0; i <= 1000; i++)p[i] = i;
			istree = true;
			continue;
		}
		if (node.find(m) == node.end())node.emplace(m, node.size());
		if (node.find(n) == node.end())node.emplace(n, node.size());
		p[findset(node[n])] = findset(node[m]);
	}
    return 0;
}

