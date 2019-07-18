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

double findslope(pair<int, int>a, pair<int, int>b){
	return (b.second - a.second)*1.0/(b.first - a.first);
}
int main()
{
	int n,i,j,k;
	while (true){
		cin >> n;
		vector<pair<int, int>>points;
		for (i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			points.push_back(make_pair(x, y));
		}
		sort(points.begin(), points.end());
		map<double, int>minn, maxx;
		set<double>t;
		for (int p = 0; p < n; p++) {
			for (int q = p + 1; q < n; q++) {
				double slopeToQ = findslope(points[p], points[q]);
				for (int r = q + 1; r < n; r++) {
					double slopeToR = findslope(points[p], points[r]);
					if (slopeToQ == slopeToR) {
						for (int s = r + 1; s < n; s++) {
							double slopeToS = findslope(points[p], points[s]);
							if (slopeToQ == slopeToS) {
								vector<pair<int, int>>collinear;
								collinear.push_back(points[p]);
								collinear.push_back(points[q]);
								collinear.push_back(points[r]);
								collinear.push_back(points[s]);
								
								sort(collinear.begin(), collinear.end());

								if (t.find(slopeToS) != t.end())continue;
								t.insert(slopeToS);

								cout << "(" << collinear[0].first << "," << collinear[0].second << ") -> ";
								cout << "(" << collinear[3].first << "," << collinear[3].second << ")\n";


							}
						}
					}
				}
			}
		}
	}
	return 0;
}
