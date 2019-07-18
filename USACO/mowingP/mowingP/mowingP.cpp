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
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

using namespace std;

long long i, j, k;
vector<set<long long>>x, y;
vector<vector<long long>>segment;
map<long long, long long>xIndex, yIndex;
bool checkIntersect(vector<long long>s, vector<long long>t){
	int x1 = s[0], y1 = s[1], x2 = s[2], y2 = s[3];
	int xx1 = t[0], yy1 = t[1], xx2 = t[2], yy2 = t[3];

	if (x2 == x1 && xx2 == xx1)return false;
	if (y2 == y1 && yy2 == yy1)return false;

	if (x1 == x2){//if first line is vertical
		if (min(y1, y2) < yy1 && yy1 < max(y1, y2) && min(xx1, xx2) < x1 && x1 < max(xx1, xx2))return true;
		return false;
	}
	//horizontal
	if (min(yy1, yy2) < y1 && y1 < max(yy1, yy2) && min(x1, x2) < xx1 && xx1 < max(x1, x2))return true;
	return false;
}
int main(){
	freopen("mowing.in", "r", stdin);
	freopen("mowing.out", "w", stdout);
	long long n, t;
	vector<pair<long long, long long>>pt;
	cin >> n >> t;
	for (i = 0; i < n; i++){
		long long x, y;
		cin >> x >> y;
		pt.push_back({ x, y });
	}
	long long ct = 0;
	for (i = 0; i < n-1; i++){
		for (j = 0; j < segment.size(); j++){
			vector<long long>a = { pt[i].first, pt[i].second, pt[i + 1].first, pt[i + 1].second };
			if (checkIntersect(a, segment[j]))ct++;
		}
		if (i + 1 >= 4){
			vector<long long>a = { pt[i-2].first, pt[i-2].second, pt[i-1].first, pt[i-1].second };
			segment.push_back(a);
		}
	}
	cout << ct << "\n";
	return 0;
}