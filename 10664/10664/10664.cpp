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


int sti(string s) {
	int m=1, ans = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		ans += m*(s[i] - '0');
		m *= 10;
	}
	return ans;
}
bool isSubsetSum(vector<int>set, int n, int sum)
{
	if (sum == 0)
		return true;
	if (n == 0 && sum != 0)
		return false;
	if (set[n - 1] > sum)
		return isSubsetSum(set, n - 1, sum);
	return isSubsetSum(set, n - 1, sum) ||
		isSubsetSum(set, n - 1, sum - set[n - 1]);
}
int main()
{
	int i, j, k, n;
	cin >> n;
	string ln;
	getline(cin, ln);
	while (n--) {
		int m = 0;
		vector<int>weight;
		string line;
		getline(cin, line);
		stringstream ss(line);
		string sa;
		long sum = 0;
		while (ss >> sa) {
			weight.push_back(sti(sa));
			sum += sti(sa);
			m++;
		}
		if (sum % 2 == 1 || m==1)cout << "NO\n";
		else {
			if (isSubsetSum(weight, m, sum / 2))cout << "YES\n";
			else cout << "NO\n";
		}
	}
    return 0;
}

