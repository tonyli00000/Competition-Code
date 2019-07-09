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

long long dist(int x1, int y1, int x2, int y2){
	return pow(x1 - x2, 2) + pow(y1 - y2, 2);
}
class BruteForce{
private: set<pair<int,int>>points;
public:
	bool isempty(){
		return points.empty();
	}
	int size(){
		return points.size();
	}
	void insert(int x,int y){
		points.insert(make_pair(x,y));
	}
	bool contains(int x, int y){

		return (points.find(make_pair(x,y)) != points.end());
	}
	void range(int x, int y, int xm, int ym){
		for (auto it = points.begin(); it != points.end(); it++){
			if (x <= it->first && it->first <= xm && y <= it->second && it->second <= ym)
				cout << it->first << " " << it->second << "\n";
		}
	}
	void nearest(int x, int y){
		int closestx, closesty;
		long long d = 10000000000;
		for (auto it = points.begin(); it != points.end(); it++){
			if (dist(it->first, it->second, x, y) < d){
				d = dist(it->first, it->second, x, y);
				closestx = it->first;
				closesty = it->second;
			}
		}
		cout << closestx << " " << closesty << "\n";
	}
};
int main()
{

	return 0;
}
