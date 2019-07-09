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


int P[501];
int G[501][501];
int n, m;
int i, j, k;
int main() {
	int tt; cin >> tt;
	while (tt--) {
		int b, p, q; cin >> b >> p >> q;
		for (int i = 0; i<q; i++)
			cin >> P[i];

		for (i = 0; i <= 500; i++){
			for (j = 0; j <= 500; j++){
				G[i][j] = 0x1f;
			}
		}

		G[0][0] = 0;
		for (int i = 1; i <= p; i++) {
			int k; cin >> k;
			G[i][i] = 0;
			for (int j = 0; j<k; j++) {
				int x, y; cin >> x >> y;
				G[i][y] = min(G[i][y], x);
			}
		}

		for (int k = 0; k <= p; k++)
			for (int i = 0; i <= p; i++)
				for (int j = 0; j <= p; j++)
					G[i][j] = min(G[i][j], G[i][k] + G[k][j]);

		int minn = 1 << 30;
		for (int i = 0; i<q; i++) {
			minn = min(minn, G[P[i]][0]);
		}

		int current = 0;
		int answer = 0;
		while (true) {
			if ((current += minn) >= b) break;
			current--;
			answer++;
		}

		cout << answer << "\n";
	}
	return 0;
}