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
int maximalRectangle(vector<vector<int>>& matrix) {
	const int row = matrix.size();
	if (0 == row) return 0;
	const int col = matrix[0].size();
	vector<vector<int>> ones(row, vector<int>(col + 1, 0));
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++) {
			if (matrix[i][j] == 1) {
				if (i>0)ones[i][j] = 1 + ones[i - 1][j];
				else ones[i][j] = 1;
			}
		}
	int max_a = 0;
	for (int i = 0; i < row; i++) {
		stack<int> stk;
		vector<int> cur = ones[i];
		int idx = 0;
		while (idx < cur.size()) {
			if (stk.empty() || cur[idx] >= cur[stk.top()]) {
				stk.push(idx++);
			}
			else {
				int h = stk.top();
				stk.pop();
				max_a = max(max_a, cur[h] * (stk.empty() ? idx : idx - stk.top() - 1));
			}
		}
	}
	return max_a;
}
int main()
{
	int t,i,j,k;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<vector<int>>mat(n, vector<int>(n, 1));
		int x;
		cin >> x;
		while (x--){
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			for (i = a - 1; i < c; i++){
				for (j = b - 1; j < d; j++){
					mat[i][j] = -12000;
				}
			}
		}
		cout << maximalRectangle(mat) << "\n";
	}
	return 0;
}
