#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int i, j, k, region[100];

bool find(int r, int count, int t) {
	int i, j, k, index;
	bool flag = false;
	if (region[t - 1] == 13 && t!=r) return false;
	if (t == r)return true;
	if (region[t - 1] + count > r)index = region[t - 1] + count - r;
	else index = region[t - 1] + count;
	//for (i = 0; i < t; i++) {
	//	if (index == region[i]) {
	//		flag = true;
	//		break;
	//	}
	
	int p = 0;
	for (i = 1; i <= count; i++) {
		for (j = 0; j < t; j++) {
			if ((region[t - 1] + i) % r == index) {
				index++;
				break;
			}
		}
	}
	//if (flag == true) {
	//	while (flag == true) {
	//		index++;
	//		if (index > r)index = 1;
	//		for (i = 0; i < t; i++)if (index == region[i])break;
	//		if (i == t)flag = false;
	//	}
	//}
	region[t] = index;
	find(r, count, t + 1);
}
int main()
{
	int r;
	while (cin >> r && r != 0) {
		for (i = 0; i < r; i++)region[i] = 0;
		region[r - 1] = 13;
		region[0] = 1;
		for (i = 1; i < r; i++) {
			if (find(r, i, 1) == true) {
				cout << i << "\n";
				break;
			}
		}
	}
	return 0;
}
