#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

#define MAXN 10005

int n;
long long p[MAXN][MAXN];

int main()
{
	int caseid;
	int i, j, a, b;
	long long total;

	caseid = 0;
	while (cin >> n, n > 0) {
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++) cin >> p[i][j];

		caseid++;
		cout << "Case " << caseid << ":";
		for (a = 1; a <= (n + 1) / 2; a++) {
			b = (n + 1) - a;
			total = 0;
			for (i = a; i <= b; i++)
				total += p[a][i] + p[b][i];
			for (i = a + 1; i <= b - 1; i++)
				total += p[i][a] + p[i][b];
			if (a == b) total /= 2;
			cout << " " << total;
		}
		cout << "\n";
	}

	return 0;
}