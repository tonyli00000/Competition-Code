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
int main() {
	long long N, s;
	cin >> N;
	while (N-- && (cin >> s))
		cout << long((sqrt(1 + 8 * s) - 1) / 2) << "\n";
	return 0;
}