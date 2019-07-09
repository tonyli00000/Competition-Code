/*
ID:tonyli21
PROG:fc
LANG:C++11
*/
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
#pragma warning(disable:4996)
#define maxn 10005
using namespace std;

using namespace std;

struct P {

	double x, y;

	P(double x = 0, double y = 0) :x(x), y(y) {}

	P operator + (P o) { return P(x + o.x, y + o.y); }
	P operator - (P o) { return P(x - o.x, y - o.y); }


	bool operator == (const P &o) const {
		return x == o.x && y == o.y;
	}
	bool operator < (const P &o) const {
		return x<o.x || (x == o.x && y<o.y);
	}

};
P ans[maxn], p[maxn];
inline double cross(P a, P b) { return a.x*b.y - a.y*b.x; }
inline double dist(P o) { return sqrt(o.x*o.x + o.y*o.y); }
double convexHull(int n) {

	sort(p, p + n);

	int m = 0;
	for(int i=0;i<n;i++) {
		while (m>1 && cross(ans[m - 1] - ans[m - 2], p[i] - ans[m - 2]) <= 0) m--;
		ans[m++] = p[i];
	}

	int k = m;
	for (int i = n - 2; i >= 0; i--) {
		while (m>k && cross(ans[m - 1] - ans[m - 2], p[i] - ans[m - 2]) <= 0) m--;
		ans[m++] = p[i];
	}

	if (n>1) m--;
	double length = 0;
	for(int i=0;i<m;i++)
		length += dist(ans[i] - ans[i + 1]);
	return length;
}
int main()
{
	freopen("fc.in", "r", stdin);
	freopen("fc.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> p[i].x >> p[i].y;
	}
	cout << fixed << setprecision(2) << convexHull(n) << "\n";
}
