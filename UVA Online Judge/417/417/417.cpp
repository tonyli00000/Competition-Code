#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map <string, long> x;
long ct = 1;

void generate2(int step,int pos,string s) {

	if (pos == step + 1) {
		x[s] = ct;
		ct++;
		return;
	}
	char i;
	if (pos==0) i = 'a';
	else i = s[pos - 1] + 1;
	for (; i <= 'z'; i++) {
			generate2(step, pos + 1, s + i);
	}
}
int main()
{
	int i, j, k;
	for (i = 0; i < 5; i++) {
		generate2(i,0,"");
	}
	string line;
	while (cin >> line) {
		unordered_map<string, long>::iterator it;
		it=x.find(line);
		if (it != x.end()) cout << x[line]<<"\n";
		else cout << "0\n";
	}
	return 0;
}
