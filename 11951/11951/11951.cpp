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

using namespace std;

int T, N, M, K;
int A[150][150];
int main()
{
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> A[i][j];
				if (i > 0) A[i][j] += A[i - 1][j];
			}
		}

		int best_cost = 0;
		int best_area = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i; j < N; j++) {
				int area = 0;
				int cost = 0;
				int start = 0;
				for (int k = 0; k < M; k++) {
					int col_sum = A[j][k];
					if (i > 0) col_sum -= A[i - 1][k];
					cost += col_sum;
					if (cost > K) {
						while (cost > K) {
							cost -= A[j][start];
							if (i > 0) cost += A[i - 1][start];
							start++;
						}
					}
					area = (k - start + 1) * (j - i + 1);
					if (area == best_area)
						if (cost < best_cost)
							best_cost = cost;
					if (area > best_area) {
						best_area = area;
						best_cost = cost;
					}

				}
			}
		}
		cout << "Case #" << t << ": " << best_area << " " << best_cost << "\n";
	}
	return 0;
}
