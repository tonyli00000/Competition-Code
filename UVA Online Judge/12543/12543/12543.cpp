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
	string line,longest="";
	int i, j, k;
	while (getline(cin, line)) {
		for (i = 0; i < line.length(); i++) {
			if (line[i] == ' ' || line[i] == '-' || (line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z'))continue;
			line.erase(i, 1);
		}
		string l;
		stringstream ss(line);
		while (ss >> l) {
			if (l == "E-N-D")goto done;
			if (l.length() > longest.length())longest = l;
		}
	}
done:
	for (i = 0; i < longest.length(); i++) {
		if (longest[i] >= 'A' && longest[i] <= 'Z')longest[i] += ('a' - 'A');
	}
	cout << longest << "\n";
	return 0;
}
