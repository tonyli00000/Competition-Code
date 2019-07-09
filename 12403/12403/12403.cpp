#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int main()
{
	long long t,i,j,k,total=0;
	cin >> t;
	string line;
	for (i = 0; i < t; i++) {
		cin >> line;
		if (line == "donate") {
			cin >> k;
			total += k;
		}
		else cout << total << "\n";
	}
	return 0;
}
