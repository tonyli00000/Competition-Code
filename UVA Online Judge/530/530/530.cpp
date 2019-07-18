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
long min(long x, long y){
	if (x<y)
		return x;
	return y;
}

long C(int n, int r) {
	long ans = 1;
	r = min(r, n - r);
	int i;
	for (i = 1; i < r + 1; i++) {
		ans *= (n - r + i);
		ans /= i;
	}

	return ans;
}

int main(){
	long n, r;
	while (1){
		cin>>n>>r;
		if (n == 0 && r == 0)
			break;
		cout << C(n, r) << "\n";

	}
	return 0;
}