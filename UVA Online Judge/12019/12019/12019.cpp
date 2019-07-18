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

int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string days[7] = { "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };

int d(int m1, int d1){
	int ans = 0;
	for (int i = 0; i < m1-1; i++){
		ans += month[i];
	}
	ans += d1;
	return ans;
}
int main()
{
	int t;
	cin >> t;
	while (t--){
		int x,y;
		cin >> x >> y;
		cout << days[(d(x, y) - 1) % 7] << "\n";
	}
	return 0;
}
