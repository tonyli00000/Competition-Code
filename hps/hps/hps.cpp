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

int m[6][3] = { {1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,2,1},{3,1,2} };
int main()
{
	int n,i,j,k;
	cin >> n;
	int a[105][2];
	for (i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[i][0] = x;
		a[i][1] = y;
	}
	int ct, maxx=0;
	for (i = 0; i < 6; i++) {
		ct = 0;
		map<int, char>letter;
		letter[1] = 'A' + m[i][0];
		letter[2] = 'A' + m[i][1];
		letter[3] = 'A' + m[i][2];
		for (j = 0; j < n; j++) {
			char q = letter[a[j][0]], w = letter[a[j][1]];
			if (q == 'B'&&w == 'D')ct++;
			if (q == 'D'&&w == 'C')ct++;
			if (q == 'C' && w == 'B')ct++;
		}
		maxx = max(ct, maxx);
	}
	cout << maxx << "\n";

    return 0;
}

