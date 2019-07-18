#include <string.h>
#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <sstream>
using namespace std;
typedef pair < int, int > ii;
char letter[50];
int tup[50];
bool p[200];
bool constraint[200][200];
int N;

bool isvalid(int d) {
	for (int i = 0; i < d; i++)
		if (constraint[letter[tup[d]]][letter[tup[i]]])
			return false;
	return true;
}
void solve(int step) {
	if (!isvalid(step))return;
	if (step == N - 1) {
		for (int i = 0; i < N; i++)cout << letter[tup[i]];
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		if (p[letter[i]] == false) {
			p[letter[i]] = true;
			tup[step + 1] = i;
			solve(step + 1);
			p[letter[i]] = false;
		}
	}
}
int main() {
	string line;
	stringstream ss;
	char a, b;
	bool blank = false;
	while (getline(cin, line)) {
		ss.clear();
		ss << line;
		N = -1;
		while (ss >> letter[++N]);
		memset(constraint, false, sizeof(constraint));
		getline(cin, line);
		ss.clear();
		ss << line;
		while (ss >> a >> b)
			constraint[a][b] = true;
		sort(letter, letter + N);
		memset(p, false, sizeof(p));
		if (blank)cout << "\n";
		blank = true;
		for (int i = 0; i < N; i++) {
			p[letter[i]] = true;
			tup[0] = i;
			solve(0);
			p[letter[i]] = false;
		}
	}
	return 0;
}