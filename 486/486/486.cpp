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
	long long sum = 0;
	map<string, long long>n;
	n["one"] = 1;
	n["two"] = 2;
	n["three"] = 3;
	n["four"] = 4;
	n["five"] = 5;
	n["six"] = 6;
	n["seven"] = 7;
	n["eight"] = 8;
	n["nine"] = 9;
	n["ten"] = 10;
	n["eleven"] = 11;
	n["twelve"] = 12;
	n["thirteen"] = 13;
	n["fourteen"] = 14;
	n["fifteen"] = 15;
	n["sixteen"] = 16;
	n["seventeen"] = 17;
	n["eighteen"] = 18;
	n["nineteen"] = 19;
	n["twenty"] = 20;
	n["thirty"] = 30;
	n["fourty"] = 40;
	n["fifty"] = 50;
	n["sixty"] = 60;
	n["seventy"] = 70;
	n["eighty"] = 80;
	n["ninety"] = 90;
	n["hundred"] = 100;
	n["thousand"] = 1000;
	n["million"] = 1000000;

	while (getline(cin, line)) {
		long long ans=0,m=0;
		bool flag = true;
		string l;
		stringstream ss(line);
		ss >> l;
		if (l == "negative")cout << "\n";
		else {
			if (n[l] != 100 || n[l] != 1000 || n[l]!=1000000)m+=
		}
		
	}
	return 0;
}
