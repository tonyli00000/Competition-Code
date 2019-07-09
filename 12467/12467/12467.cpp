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

#define MAXN 1000001

string T, P;
int b[MAXN], n, m,ans;

void kmpPreProc() {
	m = P.length();
	int i = 0, j = -1;
	b[0] = -1;
	while (i < m) {
		while (j >= 0 && P[i] != P[j])
			j = b[j];
		i++;
		j++;
		b[i] = j;
	}
}

void kmp() {
	n = T.length();
	int i = 0, j = 0;
	while (i < n) {
		while (j >= 0 && T[i] != P[j])
			j = b[j];
		i++;
		j++;
		ans = max(ans, j);
		if (j == m) j = b[j];
		
	}
}

int main() {
	int t;
		cin >> t;

	while (t--) {
		cin >> P;
		int len = P.length();
		for (int i = 0; i < len; i++) {
			T +=P[len - i - 1];
		}
		T+='\0';

		kmpPreProc();
		ans = -1;
		kmp();
		for (int i = ans - 1; i >= 0; i--) {
			cout << P[i];
		}
		cout << "\n";
	}

	return 0;
}