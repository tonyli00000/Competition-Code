// L599.cpp : Defines the entry point for the console application.
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

class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		vector<string>ret;
		map<string, int>x, y;
		int i, j, k;
		for (i = 0; i<list1.size(); i++){
			x[list1[i]] = i;
		}
		for (i = 0; i<list2.size(); i++){
			y[list2[i]] = i;
		}
		int minn = INT_MAX;
		for (auto it = x.begin(); it != x.end(); it++){
			auto f = y.find(it->first);
			if (f != y.end() && f->second){
				if (f->second + it->second<minn){
					minn = f->second + it->second;
					ret.clear();
					ret.push_back(f->first);
					continue;
				}
				if (f->second + it->second == minn)ret.push_back(f->first);
			}
		}
		return ret;
	}
};
int main()
{
	return 0;
}

