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
#define INF 10000000
#define MOD 1000000007
using namespace std;

class STMin {
public:
	vector<long long>num;
	vector<vector<long long>>minn;
	int lg = 24;
	int n;
	void build() {
		int h = log2(n);
		for (int i = 0; i < n; i++) {
			minn[i][0] = num[i];
		}
		for (int j = 1; j <= h; j++) {
			for (int k = 0; k + (1 << j) - 1 < n; k++) {
				int x = k + (1 << (j - 1));
				minn[k][j] = min(minn[k][j - 1], minn[x][j - 1]);
			}
		}
	}
	STMin(vector<long long>&x) :num(x) {
		n = x.size();
		minn.resize(n + 5, vector<long long>(lg));
		build();
	}
	long long query(int i, int j) {
		int h = log2(j - i + 1);
		return min(minn[i][h], minn[j - (1 << h) + 1][h]);
	}
};
class STMax {
public:
	vector<long long>num;
	vector<vector<long long>>maxx;
	int lg = 24;
	int n;
	void build() {
		int h = log2(n);
		for (int i = 0; i < n; i++) {
			maxx[i][0] = num[i];
		}
		for (int j = 1; j <= h; j++) {
			for (int k = 0; k + (1 << j) - 1 < n; k++) {
				int x = k + (1 << (j - 1));
				maxx[k][j] = max(maxx[k][j - 1], maxx[x][j - 1]);
			}
		}
	}
	STMax(vector<long long>&x) :num(x) {
		n = x.size();
		maxx.resize(n + 5, vector<long long>(lg));
		build();
	}
	long long query(int i, int j) {
		int h = log2(j - i + 1);
		return max(maxx[i][h], maxx[j - (1 << h) + 1][h]);
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<long long>a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	STMax* maxx = new STMax(a);
	STMin* minn = new STMin(b);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		int l = i, r = n - 1;
		int x=-1, y=-1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (maxx->query(i, mid) < minn->query(i, mid))l = mid + 1;
			else if (maxx->query(i, mid) > minn->query(i, mid))r = mid - 1;
			else {
				x = mid;
				r = mid - 1;
			}
		}
		if (x == -1)continue;
		l = i, r = n - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (maxx->query(i, mid) < minn->query(i, mid))l = mid + 1;
			else if (maxx->query(i, mid) > minn->query(i, mid))r = mid - 1;
			else {
				y = mid;
				l = mid+1;
			}
		}
		ans += (y - x + 1);
	}
	cout << ans << "\n";
	return 0;
}