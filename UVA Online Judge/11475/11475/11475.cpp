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

bool palcheck(string line) {
	int i,len=line.length();
	for (i = 0; i < len / 2; i++) {
		if (line[i] != line[len - 1 - i])break;
	}
	if (i == len / 2)return true;
	else return false;
}

int F[1000005];

void kmp_init(string& P) {
	F[0] = 0;  F[1] = 0;
	int i = 1, j = 0;
	while (i<P.size()) {
		if (P[i] == P[j])
			F[++i] = ++j;
		else if (j == 0)
			F[++i] = 0;
		else
			j = F[j];
	}
}

int kmp(string P, string T) {
	kmp_init(P);
	int i = 0, j = 0;
	int n = T.length(), m = P.length();

	while (i < n) {
		while (j < m) {
			if (P[j] == T[i]) {
				i++; j++;
			}
			else break;
		}
		if (j == 0) i++;
		if (i == n) return j;
		j = F[j];
	}
	return 0;
}
int main()
{
	string line;
	while (cin >> line) {
		string P = string(line.rbegin(), line.rend());

		string K = line.substr(0, line.size() - kmp(P, line));

		cout << line + string(K.rbegin(), K.rend()) << "\n";
	}
	return 0;
}
