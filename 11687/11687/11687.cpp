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
	string line;
	while (cin >> line&&line != "END"){
		if (line.length() >= 10)cout << 4 << "\n";
		else{
			if (line.length() >= 2)cout << 3 << "\n";
			else if (line == "1")cout << 1 << "\n";
			else cout << 2 << "\n";
		}
	}
	return 0;
}
