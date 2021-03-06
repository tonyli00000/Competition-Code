#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
using namespace std;

string line;
int main()
{
	int i, j, k,t=0,letter[30];
	bool included[30];
	while (cin >> line && line != "end") {
		stack <int> box;
		t++;
		cout << "Case " << t << ": ";
		for (i = 0; i < 26; i++) {
			included[i] = false;
			letter[i] = 0;
		}
		for (i = 0; i < line.length(); i++) {
			letter[line[i] - 'A']++;
			box.push(line[i] - 'A');
		}
		int ct = 0;
		for (i = 0; i < 26 && line.length()!=0 && line.length()!=1; i++) {
			if (letter[i] > 1) {
				bool flag = false;
				int pos = 0;
				for (j = 0; j < line.length(); j++) {
					if (!flag && line[j] - 'A' == i) {
						pos = j;
						flag = true;
					}
					else if (flag && line[j]-'A'==i) {
						if (j - pos > 1) {
							flag = false;
							break;
						}
						else pos = j;
					}
				}
				if (!flag) {
					ct++;
					for (j = 0; j <= line.length(); j++) {
						if (line[j]-'A' == i) {
							line.erase(j, 1);
							j = -1;
						}
					}
				}
			}
		}
		if(line.length()==0)cout << ct+1 << "\n";
		else {
			if (line.length() == 1)cout << ct + 1 << "\n";
			else {
				for (i = 0; i < (line.length()-1); i++) {
					if (line[i] < line[i + 1])ct++;
				}
				cout << ct + 1 << "\n";
				/*if (ct == 0)cout << "1\n";
				else cout << ct << "\n";*/
			}
		}
	}
	return 0;
}
