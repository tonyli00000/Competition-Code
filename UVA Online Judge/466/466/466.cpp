#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

double x[103], y[103], x2[103], y2[103];

bool same(int a) {
	int i, j;
	for (i = 0; i < a; i++) {
		if (x[i] != x2[i])break;
		if (y[i] != y2[i])break;
	}
	if (i == a)return true;
	else return false;
}

bool rotation_90(int a) {
	int i,j;
	for (i = 0; i < a; i++) {
		for (j = 0; j < a; j++) {
			if (y[i] == x2[j] && -1 * x[i] == y2[j])break;
		}
		if (j == a)break;
	}
	if (i == a)return true;
	else return false;
}
bool rotation_180(int a) {
	int i,j;
	for (i = 0; i < a; i++) {
		for (j = 0; j < a; j++) {
			if (-1 * x[i] == x2[j] && -1 * y[i] == y2[j])break;
		}
		if (j == a)break;
	}
	if (i == a)return true;
	else return false;
}
bool rotation_270(int a) {
	int i,j;
	for (i = 0; i < a; i++) {
		for (j = 0; j < a; j++) {
			if (-1 * y[i] == x2[j] && x[i] == y2[j])break;
		}
		if (j == a)break;
	}
	if (i == a)return true;
	else return false;
}
bool vert(int a) {
	int i,j;
	for (i = 0; i < a; i++) {
		for (j = 0; j < a; j++) {
			if (x[i] == x2[j] && -1 * y[j] == y2[j])break;
		}
		if (j == a)break;
	}
	if (i == a)return true;
	else return false;
}
int main()
{
	char c;
	int i, j, k;
	int t;
	while (cin >> t) {
		int pos = 0, ind = 0;
		double con = (t - 1) *1.0/ 2*1.0;
		for (i = 0; i < t; i++) {
			for (j = 0; j < t*2; j++) {
				cin >> c;
				if (c == 'X') {
					if (j < t) {
						x[pos] = (t-i-1)-con;
						y[pos] = j-con;
						pos++;
					}
					else {
						x2[ind] = (t-i-1)-con;
						y2[ind] = j-t-con;
						ind++;
					}
				}
			}
		}
		if (pos != ind)cout << "improperly transformed.\n";
		else {
			if (same(pos))cout << "preserved.\n";
			else {
				if(rotation_90(pos))cout << "rotated " << 90 << " degrees.\n";
				else {
					if (rotation_180(pos))cout << "rotated " << 180 << " degrees.\n";
					else {
						if(rotation_270(pos))cout << "rotated " << 270 << " degrees.\n";
						else {
							if (vert(pos))cout << "reflected vertically.\n";
							else cout<< "improperly transformed.\n";
						}
					}
				}
			}
		}
	}
	return 0;
}
