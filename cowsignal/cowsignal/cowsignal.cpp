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

int grid[15][15],i,j,p;
int m, n;
vector<int> horizontal(int i) {
	int j, k,streak=1;
	int a = grid[i][0];
	vector<int>temp;
	for (j = 1; j < n; j++) {
		if (grid[i][j] == a)streak++;
		else {
			for (k = 0; k < streak * p; k++) {
				temp.push_back(grid[i][j - 1]);
			}
			streak = 1;
		}
		a = grid[i][j];
	}
	for (k = 0; k < streak * p; k++) {
		temp.push_back(grid[i][n-1]);
	}
	return temp;
}

int main()
{
	for (i = 0; i < 15;i++){
		for (j = 0; j < 15; j++) {
			grid[i][j] = 0;
		}
	}
	cin >> m >> n >> p;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			char c;
			cin >> c;
			if (c == 'X')grid[i][j] = 1;
		}
	}
	for (i = 0; i < m; i++) {
		vector<int>x;
		x = horizontal(i);
		for (int l = 0; l < p; l++) {
			for (j = 0; j < x.size(); j++) {
				if (x[j] == 1)cout << 'X';
				else cout << '.';
			}
			cout << "\n";
		}
	}
    return 0;
}

