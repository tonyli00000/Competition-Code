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

class bit {
	vector<long>BIT;
public:
	bit(long n) {
		long size = 1;
		while (size < n) size <<= 1;
		n = size;
		BIT.assign(n + 1,0);
	}
	void add(int index, long value) {
		while (index < BIT.size()) {
			BIT[index] += value;
			index += (index&(-index));
		}
	}
	long sum(int index) {
		long ans = 0;
		while (index > 0) {
			ans += BIT[index];
			index -= (index&(-index));
		}
		return ans;
	}
	long sum(int low, int high) {
		return sum(high) - sum(low - 1);
	}
	long all() {
		return sum(BIT.size() - 1);
	}
	long above(int index) {
		return all() - sum(index);
	}
};
long solve(long n,vector<long>&p){
	bit x(n);
	long i, j, ans, ct=0;
	for (i = 0; i < n; i++){
		ct += x.above(p[i]);
		x.add(p[i], 1);
	}
	ans = ct;
	for (i = n - 1; i > 0; i--){
		ct = ct + 2 * p[i] - n - 1;
		ans = min(ans, ct);
	}
	return ans;
}
int main(){
	freopen("mincross.in", "r", stdin);
	freopen("mincross.out", "w", stdout);
	long n,i,j,k;
	cin >> n;
	vector<long>a(n), b(n),index(n),p(n);
	for (i = 0; i < n; i++){
		cin >> a[i];
		index[a[i] - 1] = i + 1;
	}
	for (i = 0; i < n; i++){
		cin >> b[i];
		p[i] = index[b[i] - 1];
	}
	long bottom = solve(n, p);
	for (i = 0; i < n; i++){
		index[b[i] - 1] = i + 1;
	}
	for (i = 0; i < n; i++){
		p[i] = index[a[i] - 1];
	}
	long top = solve(n, p);
	cout << min(bottom, top) << "\n";
	return 0;
}