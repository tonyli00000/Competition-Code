// 465.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
	char s1[1000], s2[1000];
	long double a, b;
	char c;
	while (cin >> s1 >> c >> s2)
	{

		a = atof(s1);
		b = atof(s2);

		cout << s1 << " " << c << " " << s2 << "\n";
		if (a > 2147483647)
			cout << "first number too big\n";
		if (b > 2147483647)
				cout << "second number too big\n";
		if (c == '+' && (a + b)>2147483647)
			cout << "result too big\n";
		if (c == '*' && (a*b)>2147483647)
			cout << "result too big\n";
	}
	return 0;
}
