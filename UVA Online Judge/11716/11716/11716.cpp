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

int main()
{
	int t,i,j,k;
	string line;
	cin >> t;
	getline(cin, line);
	for (k = 0; k < t; k++) {
		getline(cin, line);
		int s = sqrt(line.length());
		if (s*s != line.length())cout << "INVALID\n";
		else {
			char mat[105][105];
			for (i = 0; i < s; i++) {
				for (j = 0; j < s; j++) {
					mat[i][j] = line[i * s+j] ;
				}
			}
			for (i = 0; i < s; i++) {
				for (j = 0; j < s; j++) {
					cout << mat[j][i];
				}
			}
			cout << "\n";
		}
	}
	return 0;
}
