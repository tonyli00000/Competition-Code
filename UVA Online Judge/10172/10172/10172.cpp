#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
	int n, s, q, TC;

	cin >> TC;

	while(TC--) {
		stack<int> carrier;
		queue<int> stationQueue[100];
		cin >> n >> s >> q;
		for (int i = 0; i < n; i++) {
			int nc;
			cin >> nc;
			for (int j = 0; j < nc; j++) {
				int target;
				cin >> target;
				stationQueue[i].push(target - 1);
			}
		}
		int currPos = 0, time = 0;
		while (true) {
			while (!carrier.empty()
				&& (carrier.top() == currPos
				|| stationQueue[currPos].size() < q)) {
				if (carrier.top() != currPos) {
					stationQueue[currPos].push(carrier.top());
				}
				carrier.pop();
				time++;
			}

			while ((carrier.size() < s) && !stationQueue[currPos].empty()) {
				carrier.push(stationQueue[currPos].front());
				stationQueue[currPos].pop();
				time++;
			}

			bool clear = carrier.empty();
			for (int i = 0; i < n; i++) {
				clear &= stationQueue[i].empty();
			}
			if (clear)
				break;
			currPos = (currPos + 1) % n;
			time += 2;
		}

		cout << time << "\n";
	}

	return 0;
}