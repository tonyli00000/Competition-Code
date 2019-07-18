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
#define N 4
using namespace std;
int i, j, k;


int main()
{
		int top[N], bottom[N], left[N], right[N],mat[N][N];
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				mat[i][j] = 0;
			}
		}
		string grid,sa;
		getline(cin, grid);
		for (j = 0; j < grid.length(); j++) {
			if ('1' <= grid[j] && grid[j] <= '4')continue;
			else grid[j] = ' ';
		}
		//input
		stringstream ss(grid);
		ss >> sa;
		for (i = 0; i < N; i++) {
			top[i] = sa[i] - '0';
			if (top[i] == 1)mat[0][i] = 4;
			if (top[i] == 4) {
				for (j = 1; j <= 4; j++) {
					mat[j - 1][i] = j;
				}
			}
		}
		for (i = 0; i < 4; i++) {
			ss >> sa;
			left[i] = sa[0] - '0';
			if (left[i] == 1)mat[i][0] = 4;
			if (left[i] == 4) {
				for (j = 1; j <= 4; j++)mat[i][j - 1] = j;
			}
			if (right[i] == 4) {
				for (j = 4; j >0; j--)mat[i][4-j] = j;
			}
			if (right[i] == 1)mat[i][3] = 4;
			right[i] = sa[sa.length() - 1] - '0';
			
			for (j = 1; j < sa.length() - 1; j++)mat[i][j - 1] = sa[j] - '0';
		}
		ss >> sa;
		for (i = 0; i < N; i++) {
			bottom[i] = sa[i] - '0';
			if (bottom[i] == 1)mat[3][i] = 4;
			if (bottom[i] == 4) {
				for (j = 4; j > 0; j--) {
					mat[4 - j][i] = j;
				}
			}
		}
		vector<pair<vector<int>,vector<int>>>unused;
		unused.resize(4);
		//finding missing values and location
		for (i = 0; i < N; i++) {
			bool used[4] = { 0,0,0,0 };
			for (j = 0; j < N; j++) {
				if (!mat[j][i])unused[i].second.push_back(j);
				else used[mat[j][i] - 1] = true;
			}
			for (j = 0; j < N; j++) {
				if (!used[j])unused[i].first.push_back(j + 1);
			}
		}
		//solve
		bool found = false;
		do {
			do {
				do {
					do {
						for (i = 0; i < 4; i++) {
							for (j = 0; j < unused[i].first.size(); j++) {
								mat[unused[i].second[j]][i] = unused[i].first[j];
							}
						}
						for (i = 0; i < 4; i++) {
							bool solve = false;
							bool used[4] = { 0,0,0,0 };
							for (j = 0; j < N; j++) {
								used[mat[i][j] - 1] = true;
							}
							for (j = 0; j < N; j++) {
								if (!used[j])break;
							}
							if (j == N)solve = true;
							else break;
						}
						if (i != 4)continue;
						for (i = 0; i < 4; i++) {
							//left
							int maxx = mat[i][0],ct=1;
							for (j = 1; j < 4; j++) {
								if (mat[i][j] > maxx)ct++;
								maxx = max(maxx, mat[i][j]);
							}
							if (ct != left[i])break;
							//right
							maxx = mat[i][3], ct = 1;
							for (j = 2; j >=0; j--) {
								if (mat[i][j] > maxx)ct++;
								maxx = max(maxx, mat[i][j]);
							}
							if (ct != right[i])break;
							//top
							maxx = mat[0][i], ct = 1;
							for (j = 1; j < 4; j++) {
								if (mat[j][i] > maxx)ct++;
								maxx = max(maxx, mat[j][i]);
							}
							if (ct != top[i])break;
							//bottom
							maxx = mat[3][i], ct = 1;
							for (j = 2; j >=0; j--) {
								if (mat[j][i] > maxx)ct++;
								maxx = max(maxx, mat[j][i]);
							}
							if (ct != bottom[i])break;
						}
						if (i == 4)found = true;
					} while (!found&&next_permutation(unused[3].first.begin(), unused[3].first.end()) );
				} while (!found&&next_permutation(unused[2].first.begin(), unused[2].first.end()) && !found);
			} while (!found&&next_permutation(unused[1].first.begin(), unused[1].first.end()) && !found);
		} while (!found&&next_permutation(unused[0].first.begin(), unused[0].first.end()) && !found);
		for (k = 0; k < 5; k++) {
			char a, b;
			cin >> a >> b;
			int x = a - '1', y = b - '1';
			cout << mat[x][y] << "\n";
		}
    return 0;
}

