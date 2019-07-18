#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <stdio.h>
#include <set>

using namespace std;



multiset<int> H;
int D[20000], n;

bool pay() {
	int cost = 0;
	for (int i = 0; i < n;i++) {
		multiset<int>::iterator j = H.lower_bound(D[i]); // find the knight
		if (j == H.end()) return false; // no knight found
		cost += *j; // accumulate the cost of using the knight
		H.erase(j); // remove the knight
	}
	cout << cost << "\n";
	return true;
}

int main() {
	int m;
	while(cin>>n>>m) {
		if (n == 0 && m == 0)break;
		H.clear();
		for (int i = 0; i < n;i++) cin >> D[i];
		int h;
		for (int i = 0; i < m;i++) {
			cin >> h;
			H.insert(h);
		}
		if (!pay()) cout<<("Loowater is doomed!\n");
	}
}