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

int main()
{
	int m, n,i,j,k;
	cin >> m >> n;
	map<string, long> words;
	for (k = 0; k < m; k++) {
		string s;
		long x;
		cin >> s >> x;
		words[s] = x;
	}
	string s;
	for (i = 0; i < n; i++) {
		long long sum = 0;
		while (cin >> s && s != ".") {
			if (words.find(s) != words.end())sum += words[s];
		}
		cout << sum << "\n";
	}
	return 0;
}
