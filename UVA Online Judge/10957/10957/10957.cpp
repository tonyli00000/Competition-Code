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
int total = 0, sudoku[9][9], Queue[81][2], top, judge;
bool flag;
int check(int x, int y, int num){
	int i, j;
	for (i = 0; i < 9; i++){
		if (sudoku[x][i] == num && y != i)return 0;
		if (sudoku[i][y] == num && x != i)return 0;
	}
	int xx = x / 3 * 3, yy = y / 3 * 3;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if ((xx + i) != x && (yy + j) != y && sudoku[xx + i][yy + j] == num)return 0;
	return 1;
}
void DFS(int now){
	if (judge > 1)return;
	if (now == top){
		judge++;
		return;
	}
	for (int i = 1; i <= 9; i++){
		int x = Queue[now][0];
		int y = Queue[now][1];
		if (check(x, y, i)){
			sudoku[x][y] = i;
			DFS(now + 1);
			sudoku[x][y] = 0;
		}
	}
}


int main() {
	int i, j;
	while (cin>>sudoku[0][0]){
		flag = judge = top = 0;
		for (i = 1; i < 9; i++)
			cin>>sudoku[0][i];
		for (i = 1; i < 9; i++)
			for (j = 0; j < 9; j++)
				cin >> sudoku[i][j];
		for (i = 0; i < 9; i++)
			for (j = 0; j < 9; j++){
				if (sudoku[i][j] == 0){
					Queue[top][0] = i;
					Queue[top++][1] = j;
				}
				else{
					if (check(i, j, sudoku[i][j]) == 0)flag = true;
				}
			}
		if (flag)cout << "Case " << ++total << ": Illegal.\n";
		else{
			DFS(0);
			if (judge == 0)cout << "Case " << ++total << ": Impossible.\n";
			else if (judge == 1)cout << "Case " << ++total << ": Unique.\n";
			else cout << "Case " << ++total << ": Ambiguous.\n";
		}
	}
	return 0;
}


