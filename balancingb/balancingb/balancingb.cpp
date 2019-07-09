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
using namespace std;
#define MAXN 100005
#define MAX 10000000000
#define MAXX 1000005

const int maxn = 100010, maxl = 1000010;
int n, m;
int maxx = -1, maxy = -1;
int cur, line,pn;
vector<int>tree(MAXX), prefix(MAXX),num(MAXX);
int ans;
struct point
{
	int x, y;
}p[maxn];

bool operator < (point a, point b){
	return a.x<b.x;
}


void add(int x, int v){
	while (x <= maxx){
		tree[x] += v;
		x += (x&(-x));
	}
}
int query(int x){
	int ct = 0;
	while (x>0){
		ct += tree[x];
		x -= (x&(-x));
	}
	return ct;
}

void search(){
	int lo = 0, hi = maxy + 1;
	int botleft, botright, topleft, topright;
	while (lo + 2<hi){
		int mid = (lo + hi) >> 1, maxp;
		mid += mid % 2;
		botleft = query(mid), topleft = pn - botleft, botright = prefix[mid] - botleft, topright = n - botleft - topleft - botright;
		maxp = max(botleft, max(topleft, max(botright, topright)));
		if (maxp == topleft || maxp == topright)
			lo = mid;
		else
			hi = mid;
	}
	int x = query(lo), y = query(hi);
	ans = min(ans, max(x, max(pn - x, max(prefix[lo] - x, n - pn - prefix[lo] + x))));
	ans = min(ans, max(y, max(pn - y, max(prefix[hi] - y, n - pn - prefix[hi] + y))));
}
void solve()
{
	for (int i = 0; i<num[line]; i++, pn++)
		add(p[cur + i].y, 1);
	search();
	cur += num[line];
	line = p[cur].x;
}
int main()
{
	freopen("balancing.in", "r", stdin);
	freopen("balancing.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> p[i].x >> p[i].y;
		num[p[i].x]++;
		prefix[p[i].y]++;
		maxx = max(maxx, p[i].x);
		maxy = max(maxy, p[i].y);
	}

	for (int i = 1; i <= maxy; i++)
		prefix[i] += prefix[i - 1];
	sort(p + 1, p + n + 1);
	cur = 1; 
	pn = 0;
	line = p[1].x;

	ans = MAX;
	while (cur <= n){
		solve();
	}
	cout << ans << "\n";

	return 0;
}