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
#define INF 10000000000
using namespace std;
int r, b, c;
bool compare(long long a, vector<long long>&maxx, vector<long long>&t, vector<long long >&p){
	vector<long long>x;
	for (int i = 0; i < maxx.size(); i++){
		if (a >= p[i])x.push_back(min(maxx[i], (a - p[i]) / t[i]));
	}
	sort(x.begin(), x.end());
	long long sum = 0;
	for (int i = 0; i < x.size(); i++){
		sum += x[i];
	}
	return sum >= b;
}
int main()
{

	int t;
	cin >> t;
	for (int k = 1; k <= t; k++){
		int n;
		cin >> n;

		cin >> r >> b >> c;
		vector<long long>maxx(c), t(c), p(c);
		for (int i = 0; i < c; i++){
			cin >> maxx[i] >> t[i] >> p[i];
		}
		long long lo = 1, hi = INF;
		cout << "Case #" << k << ": ";
		long long ans = INF;
		while (lo <= hi){
			long long mid = (lo + hi) / 2;
			if (compare(mid, maxx, t, p)){
				ans = min(ans, mid);
				hi = mid - 1;
			}
			else lo = mid + 1;
		}
		cout << ans << "\n";
	}
	return 0;
}
