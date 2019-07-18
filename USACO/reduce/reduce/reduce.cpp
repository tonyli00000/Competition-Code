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
	long n,minx=50000,maxx=-1,miny=50000,maxy=-1;
	long minx2 = 50000, maxx2 = -1, miny2 = 50000, maxy2 = -1;
	cin >> n;
	vector<long>xx(n), yy(n);
	vector<pair<long, long>>coord;
	for (i = 0; i < n; i++){
		long x, y;
		cin >> x >> y;
		minx = min(minx, x);
		miny = min(miny, y);
		maxx = max(maxx, x);
		maxy = max(maxy, y);
		xx[i] = x;
		yy[i]=y;
		coord.push_back(make_pair(x, y));
	}
	sort(xx.begin(), xx.end());
	sort(yy.begin(), yy.end());
	minx2 = xx[1];
	maxx2 = xx[n - 2];
	miny2 = yy[1];
	maxy2 = yy[n - 2];
	long long res = (maxx - minx)*(maxy - miny);
	for (i = 0; i < coord.size(); i++){
		long long x = coord[i].first, y = coord[i].second;
		long long mx = maxx, my = maxy, mxx = minx, myy = miny;
		if (x == minx || x == maxx || y == maxy || y == miny){
			if (x == minx)mxx = minx2;
			if (x == maxx)mx = maxx2;
			if (y == miny)myy = miny2;
			if (y == maxy)my = maxy2;
			res = min(res, (my-myy)*(mx-mxx));
		}
		else continue;
	}
	cout << res << "\n";
	return 0;
}
