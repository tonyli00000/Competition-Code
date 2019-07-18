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
long long i, j, k;
long x[26][26][26][26];
int main()
{
	long n;
	long long ans = 0;
	cin >> n;
	for (i = 0; i < 26; i++) {
		for (j = 0; j < 26; j++) {
			for (k = 0; k < 26; k++) {
				for (int l = 0; l < 26; l++) {
					x[i][j][k][l] = 0;
				}
			}
		}
	}
	for (i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		//a.erase(a.begin() + 2, a.end());
		x[a[0]-'A'][a[1]-'A'][b[0]-'A'][b[1]-'A']++;
	}
	for (i = 0; i < 26; i++) {
		for (j = 0; j < 26; j++) {
			for (k = 0; k < 26; k++) {
				for (int l = 0; l < 26; l++) {
					if(i!=k || j!=l)ans += (x[i][j][k][l] * x[k][l][i][j]);
				}
			}
		}
	}
	cout << ans / 2 << "\n";
    return 0;
}

