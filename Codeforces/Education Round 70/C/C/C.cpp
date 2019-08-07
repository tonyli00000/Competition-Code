#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#pragma warning(disable:4996)

#define INF 10000000000
#define MOD 1000000007

#define ALL(a) a.begin(),a.end()
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
#define int long long
	vector<int>a(100000);
	for (int i = 2; i < a.size(); i++) {
		a[i] = i * (i - 1) / 2;
	}
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<int, int>ct;
		int curr = 0;
		for (int i = a.size()-1; i >= 2; i--) {
			while (a[i] <= n) {
				ct[i]++;
				//p.push_back(i);
				n -= a[i];
			}
		}
		cout << 1;
		for (auto it : ct) {
			for (int i = 0; i < it.first; i++) {
				if (curr == it.first)break;
				cout << 3;
				curr++;
			}
			for (int i = 0; i < it.second; i++) {
				cout << 7;
			}
		}
		cout << "\n";
	}
	return 0;
}