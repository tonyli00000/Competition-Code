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
	string line;
	int ct = 0;
	vector<char>out;
	while (getline(cin, line)) {
		for (int i = 0; i < line.length(); i++) {
			out.push_back(line[i]);
		}
		ct++;
	}
	for (int i = 1; i <= out.size(); i++) {
		if(i%ct==0)
	}
	return 0;
}
