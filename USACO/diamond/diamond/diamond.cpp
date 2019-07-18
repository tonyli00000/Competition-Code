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

int i, j, k;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int>diamond;
	for (i = 0; i < n; i++){
		int x;
		cin >> x;
		diamond.push_back(x);
	}
	sort(diamond.begin(), diamond.end());
	int maxx = 1, ct = 0;
	for (i = n; i >=0; i--){
		for (j = 0; j + i <= n; j++){
			if (diamond[j + i - 1] - diamond[j] <= m)break;
		}
		if (j + i != n + 1){
			maxx = i;
			break;
		}
	}
	cout << maxx << "\n";
	return 0;
}
