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

using namespace std;

int main()
{
	int t,i,j,k;
	cin >> t;
	string line;
	for (k = 0; k < t; k++) {
		cin >> line;
		int ct = 1;
		int sum = 0;
		for (i = 0; i < line.length(); i++) {
			if (line[i] == 'O') {
				sum += ct;
				ct++;
			}
			else ct = 1;
		}
		cout << sum << "\n";
	}
	return 0;
}
