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
	int tc,i,j,k;
	cin >> tc;
	string line;
	getline(cin, line);
	while (tc--) {
		//string line;
		getline(cin, line);
		map<char, int> letter;
		for (i = 0; i < line.length(); i++) {
			if (('A' <= line[i] && line[i] <= 'Z'))line[i] += ('a' - 'A');
		}
		for (i = 0; i < line.length(); i++) {
			if (('A' <= line[i] && line[i] <= 'Z') || ('a' <= line[i] && line[i] <= 'z'))letter[line[i]]++;
		}
		vector<char>out;
		int max = 0;
		for (auto it = letter.begin(); it != letter.end(); it++) {
			if (it->second > max) {
				out.clear();
				out.push_back(it->first);
				max = it->second;
			}
			else {
				if (it->second == max)out.push_back(it->first);
			}
		}
		sort(out.begin(), out.end());
		for (i = 0; i < out.size(); i++)
			cout << out[i];
		cout << "\n";
	}
	return 0;
}
