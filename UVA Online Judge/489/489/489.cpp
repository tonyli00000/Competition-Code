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

int main()
{
	int n;
	while (cin >> n && n != -1) {
		cout << "Round " << n << "\n";
		string a, b;
		map<int, int>freq;
		getline(cin, a);
		getline(cin, a);
		for (int i = 0; i < a.length(); i++) {
			freq[a[i]]++;
		}
		getline(cin, b);
		int ct = 0;
		bool win = false;
		for (int i = 0; i < b.length(); i++) {
			if (freq.find(b[i]) == freq.end())ct++;
			else freq[b[i]] = 0;
			for (auto it = freq.begin(); it != freq.end(); it++) {
				win = true;
				if (it->second != 0){
					win = false;
					break;
				}
			}
			if (win)break;
			if (ct == 7)break;
		}
		if (win)cout << "You win.\n";
		else {
			if (ct == 7)cout << "You lose.\n";
			else cout << "You chickened out.\n";
		}
	}
	return 0;
}
