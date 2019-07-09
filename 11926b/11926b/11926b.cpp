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

int n, m, s, e, r;
bool conflict;
bool t[1000100];

bool check() {
	for (int i = s; i < e; i++) {
		if (t[i]) return false;
		t[i] = true;
	}
	return true;
}

int main() {
	while (cin>>n>>m){
		if (n == 0 && m == 0) break;
		conflict = false;
		for (int i = 0; i < 1000005; i++){
			t[i] = false;
		}
		for (int i = 0; i < n; i++) {
			cin >> s >> e;
			if (!conflict && !check()) conflict = true;
		}
		for (int i = 0; i < m; i++) {
			cin >> s >> e >> r;
			while (!conflict && s < 1000000) {
				if (!check()) conflict = true;
				s += r;
				e = min(e + r, 1000000);
			}
		}
		if (!conflict) cout << "NO CONFLICT\n";
		else cout << "CONFLICT\n";
	}
}