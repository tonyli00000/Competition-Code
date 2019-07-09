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

long long i, j, k;
map<long long, pair<long long, long long>>color;
vector<long long>mat;
bool intersect(long long x, long long x2, long long y1, long long y2){
	if (x <= y1 && x2 >= y2)return true;
	if (y1 <= x2 && x2 <= y2)return true;
	return false;
}
int main()
{
	long long n;
	cin >> n;

	for (i = 0; i < n; i++){
		long long x;
		cin >> x;
		mat.push_back(x);
		if (x != 0){
			if (color.find(x) == color.end()){
				color[x].first = i;
				color[x].second = -1;
			}
			else color[x].second = max(color[x].second, i);
		}
	}
	for (auto it = color.begin(); it != color.end(); it++){
		if (it->second.second < 0)color[it->first].second = color[it->first].first;
	}
	for (auto it = color.begin(); it != color.end(); it++){
		for (auto jt = color.begin(); jt != color.end(); jt++){
			if (it != jt){
				
			}
		}
	}
	long long ans = 0;
	
	cout << ans << "\n";
	return 0;
}
