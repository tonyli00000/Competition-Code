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

const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };
int a[3][3];

void PlayMove(int r, int c)
{
	int k, i, j;
	a[r][c] = (a[r][c] + 1) % 10;
	for (k = 0; k < 4;k++){
		i = r + dx[k];
		j = c + dy[k];
		if (i >= 0 && i < 3 && j >= 0 && j < 3)
			a[i][j] = (a[i][j] + 1) % 10;
	}
}

int main() {

	int i, j, len;
	string line;
	int tc = 0;

	while (getline(cin,line)){

		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++){
				a[i][j] = 0;
			}
		}
		cout << "Case #" << ++tc << ":\n";
		len = line.length();
		for (i = 0; i < len; i++){
			char c = line[i];
			j = c - 'a';
			PlayMove(j / 3, j % 3);
		}
		for (i = 0; i < 3; i++){
			for (j = 0; j < 3; j++){
				if (j == 0) cout << a[i][j];
				else cout << " " << a[i][j];

			}
			cout << "\n";
		}
	}
	return 0;
}