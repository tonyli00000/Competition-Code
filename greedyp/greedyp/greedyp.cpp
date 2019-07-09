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
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

using namespace std;


int n;
vector<int>cow;
bool poss(int c) {
	vector<int> a;
	for (int i = 0; i < c - 1; i++){
		a.push_back(cow[i]);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++){
		if (a[i] < i + 1) return false;
	}
	return true;
}

int main() {
	freopen("greedy.in", "r", stdin);
	freopen("greedy.out", "w", stdout);
	cin >> n;
	cow.resize(n);
	for(int i=0;i<n;i++) cin >> cow[i];
	for (int i = 0; i < n; i++){
		cow[i] = n - cow[i] - 1;
	}
	int pos = 0;

	for (int i = n/2; i > 0; i /= 2) {
		while (pos + i < n && poss(pos + i)) pos += i;
	}
	cout << n - pos << "\n";
	return 0;
}