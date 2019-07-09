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

int main(){
	bool debug = 1;
	if (!debug){
		freopen("lifeguards.in", "r", stdin);
		freopen("lifeguards.out", "w", stdout);
	}
	int n;
	cin >> n;
	vector<pair<int, int>>cow(n);
	for (int i = 0; i < n; i++){
		cin >> cow[i].first >> cow[i].second;
	}
	int x = 1005;
	int ind = -1;
	sort(cow.begin(), cow.end());
	for (int i = 0; i < n; i++){
		int minn = 1005, maxx = -1;
		for (int j = i+1; j < n; j++){
			if (cow[j].first >= cow[i].second)break;
			minn = min(minn, cow[j].first);
			if (cow[j].second > cow[i].second)maxx = cow[i].second;
			else maxx = max(cow[j].second, maxx);
		}
		for (int j = i - 1; j>=0; j--){
			if (cow[j].second <= cow[i].first)break;
			if (cow[j].first < cow[i].first)minn = cow[i].first;
			else minn = min(cow[j].first, minn);
		}
		if (cow[i].second - cow[i].first - (maxx - minn) < x){
			x = cow[i].second - cow[i].first - (maxx - minn);
			ind = i;
		}
	}
	map<int, int>q;
	for (int i = 0; i < n; i++){
		for (int j = cow[i].first; j <= cow[i].second; j++){
			q[j] = 1;
		}
	}
	cout << q.size() - x << "\n";
	return 0;
}