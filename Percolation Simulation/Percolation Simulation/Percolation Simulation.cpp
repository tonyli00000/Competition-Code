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
#include <ctime>
#include <cstdio>

using namespace std;

long n, T, i, j, k;
vector<long>p, sz;
void init() {
	for (long i = 0; i < p.size(); i++) {
		p[i] = i;
	}
}
long getroot(long n) {
	return (p[n] == n) ? n : (p[n] = getroot(p[n]));
}
void join(long i, long j) {
	if (i == j)return;
	if (sz[i] < sz[j]) { p[i] = j; sz[j] += sz[i]; }
	else { p[j] = i; sz[i] += sz[j]; }
}
int main()
{
	while (cin >> n >> T) {
		if (n == -1 && T == -1)break;
		long s = 0, t = n*n + 1;
		p.resize(t + 1, 0);
		sz.resize(t + 1, 1);
		init();
		vector<bool>open(n*n + 2);
		vector<double>result(T + 2);
		std::clock_t start;
		double duration, sum = 0;
		start = std::clock();

		for (k = 0; k < T; k++) {
			bool percolates = false;
			long ct = 0;
			init();
			sz.assign(t + 1, 1);
			open.assign(open.size(), false);
			//srand(time(NULL));
			while (!percolates) {
				long long x = rand() % n, y = rand() % n;
				long square = 1 + x*n + y;
				if (open[square])continue;
				open[square] = true;
				if (square + n <= n*n && open[square + n]) {
					long x = getroot(square), y = getroot(square + n);
					if (x != y)join(x, y);
				}
				if (square - n > 0 && open[square - n]) {
					long x = getroot(square), y = getroot(square - n);
					if (x != y)join(x, y);
				}
				if (square%n != 1 && square != 1 && open[square - 1]) {
					long x = getroot(square), y = getroot(square - 1);
					if (x != y)join(x, y);
				}
				if (square%n != 0 && square != n*n && open[square + 1]) {
					long x = getroot(square), y = getroot(square + 1);
					if (x != y)join(x, y);
				}
				if (!((square - 1) / n)) {
					long x = getroot(square);
					if (x != s)join(x, s);
				}
				if (((square - 1) / n) == n - 1) {
					long x = getroot(square);
					if (x != t)join(x, t);
				}
				if (getroot(s) == getroot(t))percolates = true;
				ct++;
			}
			result[k] = ct*1.0 / n / n;
			sum += result[k];
		}
		duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
		cout << "Mean = " << sum*1.0 / T << "\n";
		std::cout << "Time: " << duration << '\n';
	}
	return 0;
}

