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
	int ans[55];
	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 3;
	ans[4] = 5;
	for (int i = 5; i < 53; i++){
		ans[i] = ans[i - 1] + ans[i - 2];
	}
	int n;
	while (cin >> n && n){
		cout << ans[n] << "\n";
	}
	return 0;
}
