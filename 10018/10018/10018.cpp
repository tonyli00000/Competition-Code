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

bool ispal(long long n) {
	int s[15];
	int i = 0;
	while (n!=0) {
		s[i++] = n % 10;
		n /= 10;
	}
	int j;
	for (j = 0; j < i; j++) {
		if (s[j] != s[i-1-j])break;
	}
	if (j==i)return true;
	else return false;
}

long long reverseNumber(long long input) {
	long long reversed = 0;
	while (input) {
		reversed = reversed * 10 + (input % 10);
		input /= 10;
	}
	return reversed;
}

int main()
{
	int t;
	cin >> t;
	long long line;
	int i, j, k;
	for (k = 0; k < t; k++) {
		cin >> line;
		int ct = 0;
		while (!ispal(line)) {
			line += reverseNumber(line);
			ct++;
		}
		cout << ct << " " << line << "\n";
	}
	return 0;
}
