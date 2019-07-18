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

long dist[805][805],i,j,k;
vector<long> grazing;
int main()
{
	long n, p, c;
	cin >> n >> p >> c;
	for (i = 0; i <= p; i++) {
		for (j = 0; j <= p; j++) {
			if (i == j)dist[i][j] = 0;
			else dist[i][j] = 1000000;
		}
	}
	for (i = 0; i < n; i++) {
		long x;
		cin >> x;
		grazing.push_back(x);
	}
	for (i = 0; i < c; i++) {
		long x, y, z;
		cin >> x >> y >> z;
		dist[x][y] = z;
		dist[y][x] = z;
	}
	for (k = 1; k <= p; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j])dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	long long minn = 1000000;
	for (i = 1; i <= p; i++) {
		long long tot=0;
		for (j = 0; j < grazing.size(); j++) {
			tot += dist[grazing[j]][i];
		}
		minn = min(minn, tot);
	}
	cout << minn << "\n";
    return 0;
}

