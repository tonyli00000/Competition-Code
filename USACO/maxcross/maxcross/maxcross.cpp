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

long long i, j;
bool working[100005];
vector<pair<long long,int>>cluster;
int main()
{
	long long n, k, b;
	cin >> n >> k >> b;
	for (i = 0; i < 100005; i++) {
		working[i] = true;
	}
	for (i = 0; i < b; i++) {
		long long x;
		cin >> x;
		working[x] = false;
	}
	long long ct = 1;
	for (i = 2; i <= n; i++) {
		if (working[i] != working[i - 1]) {
			cluster.push_back(make_pair(ct, working[i - 1]));
			ct = 1;
		}
		else ct++;
	}
	cluster.push_back(make_pair(ct, working[n]));
	ct = 0;
	long long ans = 1000000;
	if (cluster[0].second == 0)i = 1;
	else i = 0;
	for (; i < cluster.size(); i+=2) {
		long long temp=0,j=i+2;
		ct = cluster[i].first;
		while (ct < k && j<cluster.size()) {
			ct += cluster[j].first;
			temp += cluster[j - 1].first;
			ct += cluster[j - 1].first;
			j += 2;
		}
		if (ct<k);
		else ans = min(temp, ans);
	}
	cout << ans << "\n";
    return 0;
}

