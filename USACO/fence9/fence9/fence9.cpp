/*
ID:tonyli21
PROG:fence9
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

int x, y, p, t;
int gcd(int a, int b){
	if (a == 0) return b;
	while (b != 0){
		t = b;
		b = a%b;
		a = t;
	}
	return a;
}
int main(){
	freopen("fence9.in", "r", stdin);
	freopen("fence9.out", "w", stdout);
	cin >> x >> y >> p;
	cout << p*y / 2 + 1 - (gcd(x, y) + gcd(abs(x - p), y) + p) / 2 << "\n";
	return 0;
}