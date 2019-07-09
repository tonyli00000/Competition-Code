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
using namespace std;

int t, n;
int num[20];
map<vector<int>, bool > solutions;
vector<int> v;

void find(int k, int m, int sum, vector<int> v) {
	if (sum == t) {
		if (solutions[v]) return;
		solutions[v] = true;
		for (int i = 0; i < k; i++) {
			if (i != k - 1)cout << v[i] << "+";
			else cout << v[i] << "\n";
		}
		return;
	}
	if (sum > t || m == n) return;
	int i;
	for (i = m; i < n; i++) {
		v.push_back(num[i]);
		find(k + 1, i + 1, sum + num[i], v);
		v.pop_back();
	}
}

int main() {
	int i, j, k;
	while(cin>>t>>n){
		if (t == 0 && n == 0)break;
		solutions.clear();
		cout << "Sums of " << t << ":\n";
		for (i = 0; i < n; i++) {
			cin >> num[i];
		}
		find(0, 0, 0, v);
		if (solutions.empty()) cout<<("NONE\n");
	}
}