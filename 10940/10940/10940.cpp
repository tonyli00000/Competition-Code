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
	long i, ans[500005];
	ans[1] = 1;
	ans[2] = 2;
	long ct = 2,c=3;
	while (c <= 500003){
		for (i = 1; i <= ct && c<500003; i++){
			ans[c++] = i * 2;
		}
		ct *= 2;
	}
	int n;
	while (cin >> n && n){
		cout << ans[n] << "\n";
	}
	return 0;
}
