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
int i, j, k;
int n, m;

bool get(bool grid[8][8], int x, int y) {
	return x >= 0 && x < 8 && y >= 0 && y < 8 && grid[x][y];
}
int main()
{

	cin >> n >> m;
	vector<vector<bool>>master(n, vector<bool>(n,false));
	bool grids[12][8][8];
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			char c;
			cin >> c;
			if (c=='#')master[i][j]=true;
		}
	}
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++){
			for (k = 0; k < m; k++){
				char c;
				cin >> c;
				if (c == '#')grids[i][j][k] = true;
			}
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			for (int idx = -n + 1; idx <= n - 1; idx++) {
				for (int idy = -n + 1; idy <= n - 1; idy++) {
					for (int jdx = -n + 1; jdx <= n - 1; jdx++) {
						for (int jdy = -n + 1; jdy <= n - 1; jdy++) {
							bool good = true;
							for (int x = 0; good && x < n; x++) {
								for (int y = 0; good && y < n; y++) {
									bool iLoc = get(grids[i], idx + x, idy + y);
									bool jLoc = get(grids[j], jdx + x, jdy + y);
									if (iLoc && jLoc) {
										good = false;
									}
									if (master[x][y] != (iLoc || jLoc)) {
										good = false;
									}
								}
							}
							if (good) {
								cout << i + 1 << " " << j + 1 << "\n";
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
