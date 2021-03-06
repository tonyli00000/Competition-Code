#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
using namespace std;

int main()
{
	string line;
	int t=0;
	int i, j, k;
	while (cin >> line && line != "end") {
		t++;
		cout << "Case " << t << ": ";
		stack <int> box[30];
		int ind = 0;
		for (i = line.length(); i >= 0; i--) {
			for (j = 0; j <= ind; j++) {
				if (!box[j].empty()) {
					if (box[j].top() <= line[i]) {
						box[j].push(line[i]);
						break;
					}
				}
				else {
					box[j].push(line[i]);
					break;
				}
			}
			if (j == ind + 1) {
				box[ind + 1].push(line[i]);
				ind++;
			}
		}
		cout << ind+1 << "\n";
		/*int ct;
		for (i = 0; i < 26; i++) {
			if (box[i].empty()) {
				ct = i;
			}
		}
		cout << ct << "\n";*/
	}
	return 0;
}
