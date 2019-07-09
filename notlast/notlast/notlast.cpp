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


bool compare(pair<string, int>x, pair<string, int>y) {
	return (x.second < y.second);
}
int main()
{
	int n;
	cin >> n;
	string name[7] = { "Bessie", "Elsie", "Daisy", "Gertie","Annabelle", "Maggie", "Henrietta" };
	map<string, int> cow;
	for (int i = 0; i < n; i++) {
		cow[name[i]] = 0;
	}
	for (int j = 0; j < n; j++) {
		string a;
		int b;
		cin >> a >> b;
		cow[a] += b;
	}
	vector<int>x;
	for (auto it = cow.begin(); it != cow.end(); it++) {
		x.push_back()
	}
    return 0;
}

