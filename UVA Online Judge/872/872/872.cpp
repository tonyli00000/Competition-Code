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
bool no = true;
bool isvalid(int d) {
	for (int i = 0; i < d; i++)
		if (constraint[letter[tup[d]]][letter[tup[i]]])
			return false;
	return true;
}
void solve(int step) {
	if (!isvalid(step))return;
	if (step == N - 1) {
		no = false;
		for (int i = 0; i < N; i++) {
			if (i != 0)cout << " ";
			cout << letter[tup[i]];
		}
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
	int t;
	cin >> t;
	getline(cin, line);
	for (int k = 0; k < t; k++) {
		getline(cin, line);
		getline(cin, line);
		stringstream ss(line);
		N = -1;
		while (ss >> letter[++N]);
		memset(constraint, false, sizeof(constraint));
		getline(cin, line);
		for (int i = 0; i < line.length(); i++) {
			if (line[i] == '<')line[i] = ' ';
		}
		stringstream sss(line);
		while (sss >> a >> b)
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
		if (no)cout << "NO\n";
	}
	return 0;
}