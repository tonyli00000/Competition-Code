/*
ID: tonyli21
PROG: gift1
LANG: C++11
*/
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

int main(){
	int n;
	cin >> n; 
	map<string, int> money;
	vector<string>name;
	for (int i = 0; i < n; i++){
		string x;
		cin >> x;
		money[x] = 0;
		name.push_back(x);
	}
	string x;
	while (cin >> x){
		int a, b,c,r;
		cin >> a >> b;
		if (b == 0)continue;
		money[x] += -1 * a+a%b;
		r = a / b;
		for (int i = 0; i < b; i++){
			string s;
			cin >> s;
			money[s] += r;
		}
	}
	for (int i = 0; i < name.size();i++){
		cout << name[i] << " " << money[name[i]] << "\n";
	}
	return 0;
}