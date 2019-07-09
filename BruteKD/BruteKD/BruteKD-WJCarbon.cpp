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

struct point{
	int x;
	int y;
};

class BruteForce{
	set<point>points;
public:
	bool isempty(){
		return points.empty();
	}
	int size(){
		return points.size();
	}
	void insert(int x,int y){
		point p;
		p.x = x;
		p.y = y;
		points.insert(p);
	}
	bool contains(int x, int y){
		point p;
		p.x = x;
		p.y = y;
		return (points.find(p) != points.end());
	}
	void range(int x, int y, int xm, int ym){
		for (auto it = points.begin(); it != points.end(); it++){
			if (x <= it->x && it->x <= xm && y <= it->y && it->y <= ym)
				cout << it->x << " " << it->y << "\n";
		}
	}
	void nearest(int x, int y){
		for (auto it = points.begin(); it != points.end(); it++){
			
		}
	}
};
BruteForce b;
int main()
{
	b.insert(0, 0);
	b.insert(1, 2);
	b.insert(4, 4);
	b.insert(7, 7);
	return 0;
}
