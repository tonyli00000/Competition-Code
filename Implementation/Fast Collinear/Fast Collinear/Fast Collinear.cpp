#include <iostream>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <queue>
#include <climits>
#include <malloc.h>
#include <stdlib.h>
#include <cstring>
#include <cmath>
#include <sstream>
#include <map>
#include <stack>
#include <string>
#include <ctime>
#include<set>
#define INF 100000000
using namespace std;
int p;
vector<pair<int, int>>points;
double findslope(pair<int, int>a, pair<int, int>b){
	//if (b.first - a.first == 0)return INF;
	return (b.second - a.second)*1.0 / (b.first - a.first);
}
bool compare(pair<int, int>x, pair<int, int>y){
	return (findslope(points[p], x)<findslope(points[p],y));
}
int main()
{
	int n, i, j, k;
	while (true){
		cin >> n;
		points.clear();
		for (i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			points.push_back(make_pair(x, y));
		}
		set<pair<double,double>>t;
		set < pair<pair<int, int>, pair<int, int>>>out;
		for (p = 0; p < n; p++) {
			sort(points.begin(), points.end(), compare);
			vector<pair<int, int>>collinear;
			for (int q = 0; q < n; q++) {
				if (p == q) {
					continue;
				}
				double sl;
				if (collinear.empty()) {
					collinear.push_back(points[q]);
				}
				else if (findslope(points[p], points[q - 1]) == findslope(points[p], points[q])) {
					collinear.push_back(points[q]);
				}
				else if (collinear.size() >=2) {
					collinear.push_back(points[p]);
					sort(collinear.begin(), collinear.end());
					sl = abs(findslope(points[1], points[0]));
					double yint = points[1].second - 1.0*sl*points[0].first;
					if (t.find(make_pair(sl, yint)) != t.end())continue;
					t.insert(make_pair(sl, yint));
					out.insert(make_pair(make_pair(collinear[0].first, collinear[0].second), make_pair(collinear[collinear.size() - 1].first, collinear[collinear.size() - 1].second)));
					collinear.clear();
					break;
				}
				else {
					collinear.clear();
					collinear.push_back(points[q]);
				}
			}
		}
		for (auto it = out.begin(); it != out.end(); it++){
			cout << "(" << it->first.first << "," << it->first.second << ") -> ";
			cout << "(" << it->second.first << "," << it->second.second << ")\n";
		}
	}
	return 0;
}