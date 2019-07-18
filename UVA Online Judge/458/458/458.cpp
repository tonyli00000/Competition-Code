#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

string s;

int main()
{
	int i;

	while (getline(cin, s)) {
		for (i = 0; i < s.length(); i++)
			s[i] -= 7;
		cout << s << "\n";
	}
	return 0;
}