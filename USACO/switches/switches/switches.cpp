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
#include <numeric>
using namespace std;

vector<int>tovector(string x) {
	vector<int>ret(x.length());
	for (int i = 0; i < x.length(); i++) {
		ret[i] = x[i] - '0';
	}
	return ret;
}
vector<int>tobin(int n, int k) {
	vector<int>ret(k, 0);
	int x = k - 1;
	while (n) {
		ret[x--] = n % 2;
		n /= 2;
	}
	return ret;
}
int toint(string s) {
	int ret = 0,curr=1;
	for (int i = s.length() - 1; i >= 0; i--) {
		ret += curr * (s[i] - '0');
		curr *= 2;
	}
	return ret;
}
int main()
{
	int k;
	long long n;
	cin >> k >> n;
	vector<vector<int>>bin(1<<k);
	for (int i = 0; i < 1 << k; i++) {
		bin[i] = tobin(i,k);
	}
	vector<vector<int>>ct(1<<k,vector<int>(k+1,0));
	vector<bool>used(1 << k, false);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int x, y;
		cin >> x >> y;
		int a=toint(s);
		used[a]=true;
		for (int i = x; i <= y; i++) {
			ct[a][i]++;
		}
	}
	long best = 0;
	for (int i = 0; i < 1<<k; i++) {
		long curr = 0;
		for (int j = 0; j < 1 << k; j++) {
			if (!used[j])continue;
			int t = 0;
			for (int a = 0; a < k; a++) {
				if (bin[i][a] && bin[i][a] == bin[j][a])t++;
			}
			curr += ct[j][t];
		}
		best = max(best, curr);
	}
	cout << best << "\n";
	return 0;
}
