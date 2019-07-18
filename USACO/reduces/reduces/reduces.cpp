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


struct P{
	int x;
	int y;
	bool remove;
};
bool compare(P x, P y){
	if (x.x==y.x)return x.y < y.y;
	else return x.x < y.x;
}
bool compare2(P x, P y){
	if (x.y == y.y)return x.x < y.x;
	else return x.y < y.y;
}
int bitCount(unsigned int n) {
	int counter = 0;
	while (n) {
		counter += n % 2;
		n >>= 1;
	}
	return counter;
}
long long area(vector<P>points, set<int>out){
	int minX = 100000, maxX = 0;
	int minY = 100000, maxY = 0;

	for (int i = 0; i<points.size(); i++) {
		if (out.find(i)!=out.end()) continue;
		minX = min(minX, points[i].x);
		maxX = max(maxX, points[i].x);
		minY = min(minY, points[i].y);
		maxY = max(maxY, points[i].y);
	}
	return (maxX - minX)*(maxY - minY);

}
int main()
{
	int n, i, j, k;
	cin >> n;
	set<int>xx, yy;
	vector<P>points;
	int xmin = 50000, xmax = -1, ymin = 50000, ymax = -1;
	for (i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		xx.insert(x);
		yy.insert(y);
		P t;
		t.x = x;
		t.y = y;
		t.remove = false;
		points.push_back(t);
	}
	sort(points.begin(), points.end(), compare);
	for (int i = 0; i<3; i++)
		points[i].remove=true;
	for (int i = n - 3; i<n; i++)
		points[i].remove = true;
	sort(points.begin(), points.end(), compare2);
	for (int i = 0; i<3; i++)
		points[i].remove = true;
	for (int i = n - 3; i<n; i++)
		points[i].remove = true;
	vector<int>removable;
	for (i = 0; i < n; i++){
		if (points[i].remove)removable.push_back(i);
	}
	long long ans = INT_MAX;
	for (k = 0; k < (1 << removable.size()); k++){
		if (bitCount(k) != 3)continue;
		set<int>out;
		for (j = 0; j < removable.size(); j++){
			if (k&(1 << j)>0)out.insert(removable[j]);
		}
		if (out.size() > 3)continue;
		ans = min(ans, area(points, out));
	}
	cout << area << "\n";
	return 0; 
}
