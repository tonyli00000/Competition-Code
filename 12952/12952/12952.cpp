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
	int a, b;
	while (cin >> a >> b) {
		cout << max(a, b) << "\n";
	}
	return 0;
}

