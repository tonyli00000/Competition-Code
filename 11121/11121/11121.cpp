#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

string convert(long long value)
{
	string result = "";

	while (value != 0)
	{
		long long remainder = value % -2;
		value = value / -2;

		if (remainder < 0)
		{
			remainder += 2;
			value += 1;
		}

		result = char(remainder+'0') + result;
	}

	return result;
}
int main()
{
	int t;
	cin >> t;
	int i, j, k;
	for (i = 0; i < t; i++) {
		cout << "Case #" << i + 1 << ": ";
		long long value;
		cin >> value;
		if (value == 0)cout << "0\n";
		else cout << convert(value) << "\n";
	}
	return 0;
}
