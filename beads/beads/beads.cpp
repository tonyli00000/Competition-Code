/*
ID: tonyli21
PROG: bead
LANG: C++11
*/
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
#include <list>
using namespace std;

int length;
list <char> l;

int call()
{
	int count = 0;
	char temp = 'w';
	bool flag = true;

	do {
		if (flag && l.front() != 'w') {
			temp = l.front();
			flag = false;
		}
		l.pop_front();
		count++;
		//cout << l.front ();
	} while (l.size() && (l.front() == 'w' || l.front() == temp));

	temp == 'r' ? temp = 'b' : temp = 'r';

	while (l.size() && (l.back() == 'w' || l.back() == temp)) {
		l.pop_back();
		count++;
	}

	return count;
}


int main()
{
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);

	cin >> length;

	string a;
	cin >> a;

	int i, j, k;
	int max = 0;
	int value;

	for (i = 0; i < length; i++) {
		for (j = i; j < length; j++)
			l.push_back(a[j]);
		for (k = 0; k < i; k++)
			l.push_back(a[k]);
		value = call();
		if (max < value)
			max = value;
		l.clear();

	}

	cout << max << "\n";
	return 0;
}
