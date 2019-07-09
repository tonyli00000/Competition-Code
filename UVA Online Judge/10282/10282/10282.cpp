#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>

using namespace std;

map <string, string> dict;
int main()
{
	string line,s1,s2;
	while (getline(cin,line)&&line!="") {
		stringstream ss(line);
		ss >> s1;
		ss >> s2;
		dict[s2] = s1;
	}
	while (cin >> line) {
		if (dict.find(line) == dict.end())cout << "eh\n";
		else cout << dict[line]<<"\n";
	}
	return 0;
}
