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
long long n, q,i,j,k;
vector<long long>hay;

int main()
{
	long long maxx = 0;
	cin >> n >> q;
	//map<long long, long long>h;
	for (i = 0; i < n; i++) {
		long long x;
		cin >> x;
		hay.push_back(x);

	}
	sort(hay.begin(), hay.end());
	for (i = 0; i < q; i++) {
		long long a, b,ans=0;
		cin >> a >> b;
		for (j = 0; j < hay.size(); j++) {
			if (binary_search(hay.begin())ans++;
		}
		cout << hay.size() - ans << "\n";
	}
    return 0;
}

