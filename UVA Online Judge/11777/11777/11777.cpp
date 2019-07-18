// 11777.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int  x, y, z, i, j, k, b, s[3], d, e, f,average,t,g;
float score;
char a[5];
int main()
{
	a[9] = 'A';
	a[8] = 'B';
	a[7] = 'C';
	a[6] = 'D';
	a[0] = 'F';
	cin >> x;
	for (i = 0; i < x; i++)
	{
		average = 0;
		cin >> y >> z >> b>>t;
		score = y*0.2 + z*0.2 + b*0.3 + t*0.1;
		for (j = 0; j < 3; j++)
		{
			cin >> s[j];
		}
		for (j = 0; j < 3; j++)
			for (k = j + 1; k < 3; k++)
			{
				if ((s[j] + s[k]) / 2 > average)average = (s[j] + s[k]) / 2;
			}
		score = score + average*0.2;
		score = score * 100;
		if (score < 60)cout << "F\n";
		if ((score >= 60) && (score < 70))cout << "D\n";
		if ((score >= 70) && (score < 80))cout << "C\n";
		if ((score >= 80) && (score < 90))cout << "B\n";
		if (score >= 90)cout << "A\n";
	}

	return 0;
}

