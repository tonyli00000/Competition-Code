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

#define MaxSize 10
#define FillSize 13
using namespace std;
int i, j, k;

int dx[FillSize] = { 0,0,0,0,0,1,2,-1,-2,-1,1,1,-1 };
int dy[FillSize] = { -2,-1,0,1,2,0,0,0,0,-1,-1,1,1 };
int main()
{
	for (k = 0; k < 5; k++) {
		int grid[MaxSize][MaxSize];
		for (i = 0; i < MaxSize; i++) {
			for (j = 0; j < MaxSize; j++) {
				grid[i][j] = false;
			}
		}
		int n;
		cin >> n;
		string s;
		for (i = 0; i < n; i++) {
			cin >> s;
			int row = s[0] - '0';
			for (j = 1; j < s.length(); j++) {
				grid[row][s[j] - '0'] = true;
			}
		}
		cin >> n;
		for (i = 0; i < n; i++) {
			cin >> s;
			int x = s[0] - '0', y = s[1] - '0';
			for (j = 0; j < FillSize; j++) {
				if (x + dx[j]>0 && x + dx[j] <= 8 && y + dy[j]>0 && y + dy[j] <= 8) {
					if (grid[x + dx[j]][y + dy[j]])grid[x + dx[j]][y + dy[j]]=false;
					else grid[x + dx[j]][y + dy[j]] = true;
				}
			}
		}
		int ct = 0;
		for (i = 1; i <= 8; i++) {
			for (j = 1; j <= 8; j++) {
				if (grid[i][j])ct++;
			}
		}
		cout << ct << "\n";
	}
    return 0;
}

