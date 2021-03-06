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
#define INF 1000000000000
#define MOD 1000000007
using namespace std;

vector<int>p(26);
int getRoot(int x) {
	if (p[x] == x)return x;
	return getRoot(p[x]);
}
void add(int x, int y) {
	int a = getRoot(x), b = getRoot(y);
	if (a==b)return;
	p[a] = b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string x, y;
	cin >> x >> y;
	for (int i = 0; i < 26; i++) {
		p[i] = i;
	}
	vector<string>ans;
	for (int i = 0; i < n; i++) {
		if (x[i] == y[i])continue;
		if (getRoot(x[i] - 'a') == getRoot(y[i] - 'a'))continue;
		add(x[i] - 'a', y[i] - 'a');
		ans.push_back("");
		ans[ans.size() - 1] += (x[i]);
		ans[ans.size() - 1] += (" ");
		ans[ans.size() - 1] += (y[i]);
	}
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}