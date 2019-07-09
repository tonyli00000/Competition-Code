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

int main() {
	int t;
	cin >> t;
	string a, b;
	int letter[26];
	for (int i = 0; i < 26; i++) {
		letter[i] = 0;
	}
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		int temp[26],temp2[26];
		for (int j = 0; j < 26; j++) {
			temp[j] = 0;
			temp2[j] = 0;
		}
		for (int j = 0; j < a.length(); j++) {
			temp[a[j]-'a']++;
			
		}
		for (int j = 0; j < b.length(); j++) {
			temp2[b[j]-'a']++;
		}
		for (int j = 0; j < 26; j++) {
			letter[j] += (max(temp[j], temp2[j]));
		}
	}
	for (int i = 0; i < 26; i++) {
		cout << letter[i] << "\n";
	}
	return 0;
}