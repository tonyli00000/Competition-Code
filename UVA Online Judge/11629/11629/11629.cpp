#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>

using namespace std;

map <string, int> votes;

int add(string a, string b) {
	return votes[a] + votes[b];
}

bool check(string x) {
	if (x == "<" || x == ">" || x == "<=" || x == ">=" || x == "=")return false;
	else return true;
}

bool x(int sum, string line) {
	float n;
	cin >> n;
	n *= 10;
	if (line == "<" && sum < n)return true;
	else {
		if (line == ">" && sum > n)return true;
		else {
			if (line == "<=" && sum <= n)return true;
			else {
				if (line == ">=" && sum >= n)return true;
				else {
					if (line == "=" && sum == n)return true;
					else return false;
				}
			}
		}
	}
}
int main()
{
	int m, n;
	cin >> m >> n;
	int i, j, k;
	for (i = 0; i < m; i++) {
		float x;
		string line;
		cin >> line;
		cin >> x;
		votes[line] = x*10;
	}
	for (i = 0; i < n; i++) {
		int sum = 0;
		cout << "Guess #" << i + 1 << " was ";
		string line, line2;
		bool flag = true;
		while (cin >> line) {
			if (check(line)) {
				if (line == "+") {
					cin >> line;
					if (flag) {
						sum += add(line, line2);
						flag = false;
					}
					else {
						sum += votes[line];
					}
				}
				else line2 = line;
			}
			else {
				if (x(sum,line))cout << "correct.\n";
				else cout << "incorrect.\n";
				break;
			}
		}
	}
	return 0;
}
