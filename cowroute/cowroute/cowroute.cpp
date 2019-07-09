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


#define INF (int)1e9

int main() {
	freopen("cowroute.in", "r", stdin);
	freopen("cowroute.out", "w", stdout);
	int A, B, N;
	cin >> A >> B >> N;
	int result = INF;
	for (int i = 0; i < N; i++) {
		int cost, sz;
		cin >> cost >> sz;
		bool found = false;
		for (int j = 0; j < sz; j++) {
			int city;
			cin >> city;
			if (city == A) {
				found = true;
			}
			if (found && city == B) {
				result = min(result, cost);
			}
		}
	}
	if (result == INF) {
		cout << "-1\n";
	}
	else {
		cout << result << '\n';
	}
	return 0;
}