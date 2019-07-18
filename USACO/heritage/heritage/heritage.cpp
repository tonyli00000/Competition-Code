/*
ID:tonyli21
PROG:heritage
LANG:C++11
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
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

using namespace std;

string post;

void build(string pre, string in)
{
	if (pre.size() == 0) return;
	int pos = in.find(pre[0]);
	build(pre.substr(1, pos), in.substr(0, pos));
	build(pre.substr(pos + 1), in.substr(pos + 1));
	post += pre[0];
}
int main(){
	freopen("heritage.in", "r", stdin);
	freopen("heritage.out", "w", stdout);
	string pre, in;
	cin >> in >> pre;
	build(pre, in);
	cout << post << "\n";
	return 0;
}