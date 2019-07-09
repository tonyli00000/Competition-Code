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
#define INF 10000000000000
#define MOD 1000000007
using namespace std;

struct cow {
	long long h;
	long long w;
	long long s;
};
bool comp(cow x, cow y) {
	return x.s+x.w > y.s+y.w;
}
vector<cow>T;
vector<vector<bool>>all;
vector<bool>a;
vector<bool>tobin(long long x,int n) {
	a.resize(n);
	for (int i = n - 1; i >= 0; i--) {
		a[i] = x % 2;
		x /= 2;
	}
	return a;
}
void generate(int n) {
	for (long long i = 1; i <= (1 << n); i++) {
		all[i - 1] = tobin(i,n);
	}
}
int main()
{
	freopen("guard.in", "r", stdin);
	freopen("guard.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	long long h;
	cin >> n >> h;
	T.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> T[i].h>>T[i].w>>T[i].s;
	}
	all.resize(1 << n, vector<bool>(n));
	generate(n);
	sort(T.begin(), T.end(),comp);
	long long maxx = -1;
	long long i;
	for (i = 0; i < all.size(); i++) {
		long long weight = 0, height = 0,safe=INF;
		bool found = true;
		for (int j = n - 1; j >= 0; j--) {
			if (all[i][j] == 0)continue;
			if (T[j].s < weight) {
				found = false;
				break;
			}
			safe = min(safe, T[j].s - weight);
			height += T[j].h;
			weight += T[j].w;
		}
		if (!found)continue;
		if (height < h)continue;
		maxx = max(maxx, safe);
	}
	if (maxx == -1)cout << "Mark is too tall\n";
	else cout << maxx << "\n";
	return 0;
}