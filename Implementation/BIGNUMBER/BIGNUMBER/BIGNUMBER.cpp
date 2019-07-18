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

#define l 6
vector<vector<int>>number;
using namespace std;


string add(string a,string b){
	vector<vector<int>>x, y,z;
	z.resize(max(a.length(), b.length()) + 3);
	for (int i = 0; i < z.size(); i++) {
		z[i].resize(l,0);
	}
	number.clear();
	neutralize(a);
	x = number;
	number.clear();
	neutralize(b);
	y = number;
	int i, j, k;
	for (i = 0; i < a.length(); i++) {
		z[i / 6][i % 6] += x[i / 6][i % 6];
	}
	for (i = 0; i < b.length(); i++) {
		z[i / 6][i % 6] += y[i / 6][i % 6];
	}
	string ret = "";
	for (i = z.size()-1; i >=0; i--) {
		for (j = 0; j < l-1; j++) {
			if (z[i][j]>9) {
				z[i][j + 1] = z[i][j] / 10;
				z[i][j] = z[i][j] % 10;
			}
		}
		if (z[i][j]>9) {
			z[i+1][0] += z[i][j] / 10;
			z[i][j] = z[i][j] % 10;
		}
		ret += (z[i][j] + '0');
	}
	return ret;
}
void multiply() {

}
void neutralize(string s) {
	int i;
	for (i = 0; i < s.length(); i++) {
		number[i / l].push_back(s[i] - '0');
	}
}
int main()
{
	return 0;
}
