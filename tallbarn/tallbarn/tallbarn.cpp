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
#pragma warning(disable:4996)

using namespace std;
int n;
long long K;
vector<double> num(100005);

long long solve(double x){ 
	return (long long)((sqrt(1 + 4 * x) - 1) / 2); 
}
bool check(double x){
	long long l = K;
	long long sum = 0;
	for (int i = 1; i <= n; i++){
		if (num[i] <= x) continue;
		long long xx = solve(num[i] / x);
		sum += xx;
	}
	if (sum>l) return false;
	return true;
}
int main()
{
	freopen("tallbarn.in", "r", stdin);
	freopen("tallbarn.out", "w", stdout);
	long long ans = 1000000000000;
	cin >> n >> K;
	K = K - n;
	for (int i = 1; i <= n; i++) cin >> num[i];
	double lo = 0, hi = 1000000000000, mid;
	for (int i = 1; i <= 200; i++){
		mid = (lo + hi) / 2;
		if (check(mid)) hi = mid;
		else lo = mid; 
	}
	int i;
	for (i = 1, lo = 0; i <= n; ++i){
		double tmp = solve(num[i] / hi) + 1.0;
		lo += num[i] / tmp;
	}
	cout << (long long)(lo + 0.5);
	return 0;
}