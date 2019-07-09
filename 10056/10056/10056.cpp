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
	int S;
	cin >> S;
	while (S--) {
		int N, I;
		double p;
		cin >> N >> p >> I;
		printf("%.4lf\n", p ? pow(1.0 - p, I - 1) * p / (1 - pow(1.0 - p, N)) : 0);
	}
	return 0;
}