/*
ID: tonyli21
PROG: friday
LANG: C++11
*/
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
int daysinmonth(int month, int year){
	if (month == 1)
		return ((year % 4) || (!(year % 100) && ((year + 300) % 400))) ? 28 : 29;
	switch (month){
	case 8:
	case 3:
	case 5:
	case 10:
		return 30;
	default:
		return 31;
	}
}

int main() {
	freopen("friday.in", "r", stdin);
	freopen("friday.out", "w", stdout);
	int N;
	cin >> N;
	if (N < 0) N = 0;
	if (N > 400) N = 400;
	int result[7] = { 0 };
	int dow = 0, month = 0;
	for (int i = 0; i < N; i++)
		for (int m = 0; m < 12; m++){
			result[((dow + 6) % 7)]++;
			dow = (dow + daysinmonth(m, i)) % 7;
		}
	for (int i = 0; i < 7; ++i){
		cout << result[(i + 6) % 7];
		if (i == 6) cout<<"\n";
		else cout << " ";
	}
	return 0;
}