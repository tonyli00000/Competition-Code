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

bool colored[5][5],isvalid[16];
int solution = 0,rook;
void solve(int step, int n,bool visited[5][5],int x,int y){
	if (x == -1 && y == -1);
	else visited[x][y] = true;
	rook = max(step, rook);
	int i, j,k,w;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if (!colored[i][j] && !visited[i][j]){
				bool hor = true;
				for (k = i - 1; k >= 0; k--){
					if (colored[k][j])break;
					if (visited[k][j]){
						hor = false;
						break;
					}
				}
				for (k = i + 1; k < n; k++){
					if (colored[k][j])break;
					if (visited[k][j]){
						hor = false;
						break;
					}
				}
				bool vert = true;
				for (k = j - 1; k >= 0; k--){
					if (colored[i][k])break;
					if (visited[i][k]){
						hor = false;
						break;
					}
				}
				for (k = i + 1; k < n; k++){
					if (colored[i][k])break;
					if (visited[i][k]){
						hor = false;
						break;
					}
				}
				if (hor && vert)solve(++step, n, visited, i, j);
			}
		}
	}

	return;
}
int main()
{
	int n,i,j,k;
	while (cin >> n && n){
		for (i = 0; i < n; i++){
			for (j = 0; j < 5; j++){
				colored[i][j] = false;
			}
		}
		for (i = 0; i < 16; i++)
			isvalid[i] = false;
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				char c;
				cin >> c;
				if (c == 'X')colored[i][j] = true;
			}
		}
		bool a[5][5];
		solution = 0;
		rook = 0;
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				if (!colored[i][j]){
					for (i = 0; i < 5; i++){
						for (j = 0; j < 5; j++){
							a[i][j] = false;
						}
					}
					solve(0, n, a, -1, -1);
				}
				solution = max(solution, rook);
			}
		}
		cout << solution << "\n";
	}
	return 0;
}
