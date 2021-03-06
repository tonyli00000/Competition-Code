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

using namespace std;

int main()
{
	string line,x[210];
	int i, j, k;
	set <string> words;
	while (getline(cin, line)) {
		int ct = 1;
		for (i = 0; i < line.length(); i++) {
			if (('a' <= line[i] && 'z' >= line[i]) || (line[i] == ' ' && line[i - 1] != ' ') || ('A' <= line[i] && 'Z' >= line[i])) {
				if (line[i] == ' ')ct++;
				else if (line[i] <= 'Z')line[i] = line[i] - ('A' - 'a');
			}
			else {
				bool flag = false;
				if (line[i - 1] != ' ')line[i] = ' ';
				else {
					line.erase(i, 1);
					i--;
				}
			}
		}
		stringstream ss(line);
		ss << line;
		string l;
		while(ss>>l && l!=""){

			if(words.find(l)==words.end())words.insert(l);
		}
	}
	set <string>::iterator it;
	for (it = words.begin(); it != words.end(); it++)
		cout << *it << "\n";
	return 0;
}
