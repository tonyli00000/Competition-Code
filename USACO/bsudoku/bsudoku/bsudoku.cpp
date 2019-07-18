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

bool m[10][10];
int dp[10][10][1 << 9][1 << 3][2];
int dfs(int x, int y, int a, int b, bool c){
	if (x == 9) {
		if (a)return 100000;
		else return 0;
	}
	if (y == 9){
		if (c) return 100000;
		if (!((x + 1) % 3) && b) return 100000;
		dfs(x + 1, 0, a, b, 0);
	}
	else{
		if (dp[x][y][a][b][c] != -1) return dp[x][y][a][b][c];
		dp[x][y][a][b][c] = !m[x][y] + dfs(x, y + 1, a ^ 1 << y, b ^ 1 << y / 3, !c);
		dp[x][y][a][b][c] = min(dp[x][y][a][b][c], m[x][y] + dfs(x, y + 1, a, b, c));
		return dp[x][y][a][b][c];
	}
}
int main(){
	string s;
	for(int i=0;i<9;i++){
		getline(cin, s);
		for (int j = 0; j < 9; j++){
			if (s[j] == '1')m[i][j] = true;
			else m[i][j] = false;
		}
	}
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			for (int k = 0; k < 1 << 9; k++){
				for (int l = 0; l < 1 << 3; l++){
					dp[i][j][k][l][0] = -1;
					dp[i][j][k][l][1] = -1;
				}
			}
		}
	}
	cout << dfs(0, 0, 0, 0, 0) << "\n";
	return 0;
}
