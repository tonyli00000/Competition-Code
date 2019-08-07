#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#pragma warning(disable:4996)

#define INF 10000000000
#define MOD 1000000007

#define ALL(a) a.begin(),a.end()
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
//#define int long long
	string s;
	cin >> s;
	int T[10][10][10];
	memset(T, -1, sizeof(T));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int x = 0; x <= 100; x++) {
				for (int y = 0; y <= 100; y++) {
					if (x == 0 && y == 0) {
					//	T[i][j][0] = 0;
						continue;
					}
					int p = (x * i + y * j) % 10;
					
					if (T[i][j][p] == -1)T[i][j][p] = x + y;
					else T[i][j][p] = min(T[i][j][p], x + y);
				}
			}

		}
	}
	vector<vector<int>>ans(10, vector<int>(10, 0));
	vector<vector<bool>>bad(10, vector<bool>(10, false));
	for (int i = 0; i < s.length() - 1; i++) {
		int diff = (s[i + 1] - s[i]+10)%10;
		//if (diff == 0)continue;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if (T[j][k][diff] == -1)bad[j][k] = true;
				ans[j][k] += T[j][k][diff]-1;
				
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (bad[i][j])cout << -1 << " ";
			else {
				cout << ans[i][j] << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}