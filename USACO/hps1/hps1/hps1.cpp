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
long i, j, k;
int main()
{
	int game[100005];
	long n;
	cin >> n;
	for (i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == 'P')game[i] = 2;
		else {
			if (c == 'H')game[i] = 1;
			else game[i] = 3;
		}
	}
	long maxx = -1;
	long a1 = 0, b1 = 0, c1 = 0, a2 = 0, b2 = 0, c2 = 0;
	for (j = 0; j <= 0; j++) {
		if (game[j] == 1)a1++;
		else {
			if (game[j] == 2)b1++;
			else c1++;
		}
	}
	for (j = 1; j < n; j++) {
		if (game[j] == 1)a2++;
		else {
			if (game[j] == 2)b2++;
			else c2++;
		}
	}
	for (i = 0; i < n-1; i++) {
		bool a=false, b=false, c = false;
		if (i == 0);
		else {
			if (game[i] == 1) {
				a1++;
				a = true;
			}
			else {
				if (game[i] == 2) {
					b1++;
					b = true;
				}
				else {
					c1++;
					c = true;
				}
			}
		}
		if (a)a2--;
		if (b)b2--;
		if (c)c2--;
		maxx = max(a1 + b2, maxx);
		maxx = max(b1 + a2, maxx);
		maxx = max(a1 + c2,maxx);
		maxx = max(c1 + a2,maxx);
		maxx = max(c1 + b2, maxx);
		maxx = max(b1 + c2, maxx);
		maxx = max(a1 + a2, maxx);
		maxx = max(b1 + b2, maxx);
		maxx = max(c1 + c2, maxx);

	}
	cout << maxx << "\n";
    return 0;
}

