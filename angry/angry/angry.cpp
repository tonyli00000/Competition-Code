/*
ID: tonyli21
PROG: angry
LANG: C++11
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

using namespace std;

vector<long long>x;
int explode(int loc, bool direct) {
	int l = loc;
	int increment = 1;

	while (l > 0 && l < x.size() - 1) {
		int d = 0;
		if (direct) d = -1;

		else d = 1;
		int index = l;
		while (index + d >= 0 && index + d < x.size() && abs(x[index + d] - x[l]) <= increment) {
			index += d;
		}
		if (index == l) break;
		l = index;
		increment++;
	}
	return l;
}
//int simulate(long long loc,int n) {
//	bool explode = true;
//	int increment = 1,ct=1,c=0,n;
//	queue<int>explosion;
//	explosion.push(loc);
//	while(!explosion.empty()){
//		int a = explosion.front();
//		if (a == 0) {
//			for (int i = a+1; i < n; i++) {
//				if (x[i] - x[a] <= increment) {
//					explode = true;
//					ct++;
//					explosion.push(i);
//				}
//				else break;
//			}
//			increment++;
//			continue;
//		}
//		else {
//			if (loc == n - 1) {
//				for (int i = loc -1; i >=0; i--) {
//					if (x[loc] - x[i] <= increment) {
//						explode = true;
//						ct++;
//						explosion.push(i);
//					}
//					else break;
//				}
//				increment++;
//				continue;
//			}
//			else {
//				for (int i = loc - 1; i >= 0; i--) {
//					if (x[loc] - x[i] <= increment) {
//						explode = true;
//						ct++;
//					}
//					else break;
//				}
//				increment++;
//				continue;
//			}
//		}
//	}
//}
int main()
{
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
	int n, i, j, k;
	cin >> n;
	for (i = 0; i < n; i++) {
		long long y;
		cin >> y;
		x.push_back(y);
	}
	sort(x.begin(), x.end());
	int ans = 1;
	for (i = 0; i < n;i++) {
		int left = explode(i, true);
		int right = explode(i, false);
		int temp = right - left + 1;
		ans = max(ans, temp);
	}
	cout << ans << "\n";
	return 0;
}
