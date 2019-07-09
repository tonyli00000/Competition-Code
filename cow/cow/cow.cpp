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

int main()
{
	long long n;
	cin >> n;
	vector<pair<long long, long long>>x;
	long long C = 0, W = 0;
	for (int  i = 0; i < n; i++){
		char c;
		cin >> c;
		if (c == 'C')C++;
		if (c == 'W')W++;
		if (c == 'O')x.push_back(make_pair(C, W));
	}
	long long ret = 0;
	for (long long i = 0; i < x.size(); i++){
		x[i].second = W - x[i].second;
		ret += (x[i].first*x[i].second);
	}
	cout << ret << "\n";
	return 0;
}
