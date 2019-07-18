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
	long long S, D;
	while (cin>>S>>D) {
		double x = ((S - 1)*S) / 2.0;
		double y = ((double)D + x) * 2;
		double z = ((sqrt((y * 4) + 1)) / 2.0) + 0.5;
		int ans = z;
		if (z - ans<1e-7) {
			ans--;
		}
		cout << ans << "\n";
	}
	return 0;
}