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

struct expression {
	string function;
	char v;
};

pair<int, int> calc(vector<expression>&over, vector<expression>&under) {
	int x, y, w, z;
	for (auto i : over) {
		if (i.function == "sin")x++;
		else y++;
	}
	for (auto i : under) {
		if (i.function == "sin")x--;
		else y--;
	}
}

int main()
{
	while (true) {
		vector<expression>over, under;
		string line; getline(cin, line);
		stringstream ss(line);
		string x;
		bool div = false;
		while (ss >> x) {
			if (x.length() == 1 && x != "/")continue;
			if (x == "/") {
				div = true;
				continue;
			}
			if (x == "tan") {
				over.push_back({ "sin",'x' });
				under.push_back({ "cos",'x' });
			}
			if (x == "cot") {
				over.push_back({ "cos",'x' });
				under.push_back({ "sin",'x' });
			}
			if (x == "sin")over.push_back({ "sin",'x' });
			if (x == "cos")over.push_back({ "cos",'x' });
			if (x == "csc")under.push_back({ "sin",'x' });
			if (x == "sec")under.push_back({ "cos",'x' });
		}
		pair<int, int>f = calc(over, under);
		getline(cin, line);
		stringstream sss(line);
		over.clear();
		under.clear();
		while (sss >> x) {
			if (x.length() == 1 && x != "/")continue;
			if (x == "tan") {
				over.push_back({ "sin",'x' });
				under.push_back({ "cos",'x' });
			}
			if (x == "cot") {
				over.push_back({ "cos",'x' });
				under.push_back({ "sin",'x' });
			}
			if (x == "sin")over.push_back({ "sin",'x' });
			if (x == "cos")over.push_back({ "cos",'x' });
			if (x == "csc")under.push_back({ "sin",'x' });
			if (x == "sec")under.push_back({ "cos",'x' });
		}
		if (calc(over, under) == f)cout << "Equal" << "\n";
		else cout << "Not equal\n";
	}
	return 0;
}

