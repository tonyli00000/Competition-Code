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

int main() {
	int n,i,j,k;
	while (cin>>n && n) {
		int rank[10005] = {}, err = 0;
		int x, v;
		for (i = 0; i < n; i++) {
			cin >> x >> v;
			if (i + v < 0) err = 1;
			if (i + v >= n) err = 1;
			if (!err && rank[i + v])err = 1;
			if (err) continue;
			rank[i + v] = x;
		}
		if (err) {
			cout << -1 << "\n";
			continue;
		}
		cout << rank[0];
		for (i = 1; i < n; i++)
			cout<<" "<<rank[i];
		cout << "\n";
	}
	return 0;
}