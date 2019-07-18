
#include <fstream>
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

long i, j, k, p[205];

long parent(long x) {
	while (p[x] != x) {
		return parent(p[x]);
	}
	return x;
}
void join(long x, long y) {
	p[y] = x;
}
long long dist(long x1, long y1, long x2, long y2) {
	long x = x2 - x1, y = y2 - y1;
	return (x*x + y*y);
}

ofstream fout("moocast.out");
ifstream fin("moocast.in");

int main()
{
	int n;
	cin >> n;
	

	return 0;
}


