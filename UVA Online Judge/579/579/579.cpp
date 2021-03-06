#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>

using namespace std;

int i, j, k;
int main()
{
	string line;
	while (cin >> line && line != "0:00") {
		for (i = 0; i < line.length(); i++) {
			if (line[i] == ':')break;
		}
		double hr, min;
		if (i == 2)hr = 10 + line[1] - '0';
		else hr = line[0] - '0';
		min = 10 * (line[i + 1] - '0') + line[i + 2]-'0';
		hr = hr * 30 + min*1.0 / 2 * 1.0;
		min *= 6;
		if (min == 0)min = 360;
		double x = min - hr;
		if (x < 0)x *= -1;
		if(x>180)cout << fixed << setprecision(3) << 360-x << "\n";
		else cout << fixed<<setprecision(3)<<x<<"\n";
	}
	return 0;
}
