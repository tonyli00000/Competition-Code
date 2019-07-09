#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

#define MAXN 105

string s;
int n[MAXN], len;

int main()
{
	int i, j;

	for (i = 0; i < MAXN; i++) n[i] = 0;

	while (getline(cin, s), s != "0")
	{
		len = s.length();
		for (i = 0; i < len; i++)
			n[i] += s[len - 1 - i] - '0';
	}
	for (i = 0; i < MAXN - 1; i++)
	{
		n[i + 1] += n[i] / 10;
		n[i] %= 10;
	}
	i = MAXN - 1;
	while (n[i] == 0) i--;
	for (; i >= 0; i--) cout << n[i];
	cout << "\n";

	return 0;
}
