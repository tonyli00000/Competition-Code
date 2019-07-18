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

int main()
{
	int t;
	cin >> t;
	map<char, long>e;
	e['B'] = 1;
	e['U'] = 10;
	e['S'] = 100;
	e['P'] = 1000;
	e['F'] = 10000;
	e['T'] = 100000;
	e['M'] = 1000000;
	while (t--){
		string line,temp;
		cin >> line;
		temp = line;
		bool istrue = true;

		map<char, bool>used;
		map<char, int>ct;
		long long ans = 0;
		int i;
		for (i = 0; i < line.length(); i++){
			if (used.find(line[i]) != used.end())break;
			if (i != 0 && line[i] != line[i - 1])used[line[i - 1]] = true;
			ct[line[i]]++;
			if (ct[line[i]] > 9)break;
			ans += e[line[i]];
		}
		if (i == line.length())cout << ans << "\n";
		else cout << "error\n";
	}
	return 0;
}
