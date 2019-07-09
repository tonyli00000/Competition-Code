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
	string censor, S;
	cin >> S >> censor;
	string ret;
	for (long long i = 0; i < S.size(); i++) {
		ret += S[i];
		if (ret.size() >= censor.size() && ret.substr(ret.size() - censor.size()) == censor) ret.resize(ret.size() - censor.size());
	}
	cout << ret << "\n";
	return 0;
}
