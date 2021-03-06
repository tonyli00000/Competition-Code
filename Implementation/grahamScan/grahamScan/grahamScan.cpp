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

class Point {
public:
	long long x, y;
	bool operator < (Point b) {
		if (y != b.y)
			return y < b.y;
		return x < b.x;
	}
};

Point pivot;
int ccw(Point a, Point b, Point c) {
	long long area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (area > 0)
		return -1;
	else if (area < 0)
		return 1;
	return 0;
}

long long sqrDist(Point a, Point b) {
	long long dx = a.x - b.x, dy = a.y - b.y;
	return dx * dx + dy * dy;
}

bool POLAR_ORDER(Point a, Point b) {
	int order = ccw(pivot, a, b);
	if (order == 0)
		return sqrDist(pivot, a) < sqrDist(pivot, b);
	return (order == -1);
}

stack<Point> grahamScan(vector<Point> points, int N) {
	stack<Point> hull;
	//int N = points.size();
	if (N < 3)return hull;

	int leastY = 0;
	for (int i = 1; i < N; i++)
		if (points[i] < points[leastY])leastY = i;
	Point temp = points[0];
	points[0] = points[leastY];
	points[leastY] = temp;

	pivot = points[0];
	sort(points.begin() + 1, points.end(), POLAR_ORDER);

	hull.push(points[0]);
	hull.push(points[1]);
	hull.push(points[2]);

	for (int i = 3; i < N; i++) {
		Point top = hull.top();
		hull.pop();
		while (ccw(hull.top(), top, points[i]) != -1) {
			top = hull.top();
			hull.pop();
		}
		hull.push(top);
		hull.push(points[i]);
	}
	return hull;
}
int main()
{
	int n;
	cin >> n;
	vector<Point>pt(n);
	for (int i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		pt[i] = { x,y };
	}
	stack<Point>x = grahamScan(pt, n);
	cout << x.size() << "\n";
	return 0;
}



