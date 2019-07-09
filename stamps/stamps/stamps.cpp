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
int mins[2000005];

int main()
{
	int k, n;
	cin >> k >> n;
	vector<int>coin;
	for (i = 0; i < n; i++) {
		int x;
		cin >> x;
		coin.push_back(x);
	}
	for (i = 0; i < 2000005; i++) {
		mins[i] = 300;
	}
	bool solved = true;
	mins[0] = 0;
	for (i = 0;mins[i]<=k && mins[i]!=300; i++) {
		for (j = 0; j < coin.size(); j++) {
			if(coin[j]+i<=2000000)
				mins[coin[j] + i] = min(mins[coin[j] + i], mins[i] + 1);
		}
	}
	cout << i-1 << "\n";
    return 0;
}

