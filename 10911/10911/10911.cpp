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


struct student {
	string name;
	int x;
	int y;
};

int n;
student students[16];
bool taken[16];
double ans;
double curr;

double dist(int a, int b) {
	return sqrt((students[a].x - students[b].x) * (students[a].x - students[b].x) + (students[a].y - students[b].y) * (students[a].y - students[b].y));
}

void solve(int step) {
	if (step == n) {
		ans = min(curr, ans);
		return;
	}

	int st;

	// grab any available student
	for (int i = 0; i < 2*n; i++) {
		if (taken[i] == false) {
			st = i;
			taken[i] = true;
			break;
		}
	}

	// go over all available pairs for selected student
	for (int i = 0; i < 2*n; i++) {
		if (taken[i] == false) {
			taken[i] = true;
			double d = dist(st, i);
			curr += d;
			if (curr > ans) {
				curr -= d;
				taken[i] = false;
				continue;
			}
			solve(step + 1);
			curr -= d;
			taken[i] = false;
		}
	}

	taken[st] = false;
}

int main() {
	int t = 0;

	while (cin >> n && n) {
		curr = 0;
		ans = 100000000;
		for (int i = 0; i < 16; i++){
			taken[i] = false;
		}
		for (int i = 0; i < 2 * n; i++) {
			cin >> students[i].name >> students[i].x >> students[i].y;
		}

		solve(0);

		cout << "Case " << ++t << ": " << fixed << setprecision(2) << ans << endl;
	}

	return 0;
}