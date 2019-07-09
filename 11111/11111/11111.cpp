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

long long getint(string s) {
	long long ans = 0;
	bool negative = false;
	if (s[0] == '-') {
		negative = true;
		long long m = 1;
		for (int i = s.length() - 1; i > 0; i--) {
			ans += ((s[i] - '0')*m);
			m *= 10;
		}
		ans *= -1;
		return ans;
	}
	else {
		long long m = 1;
		for (int i = s.length() - 1; i >= 0; i--) {
			ans += ((s[i] - '0')*m);
			m *= 10;
		}
		return ans;
	}
}
int main()
{
	string line;
	while (getline(cin, line)) {
		stringstream ss(line);
		string l;
		vector<long long>n;
		bool out = true;
		while (ss >> l) {
			n.push_back(getint(l));
			if (n.size()!=1 && n[n.size() - 1] <= n[n.size() - 2]) {
				out = false;
				break;
			}
		}
		if (out)cout << ":-) Matrioshka!\n";
		else cout << ":-( Try again.\n";
	}
	return 0;
}
