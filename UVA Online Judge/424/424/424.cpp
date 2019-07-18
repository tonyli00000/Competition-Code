#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
string s, y;
int i, j, k, x,c[105],p,o, sum[307], digits[105][110],f;
int main()
{
	x = -1;
	for (i = 0; i < 307; i++)sum[i] = 0;
	for (i = 0; i < 105; i++)c[i] = 0;
	for (i = 0; i < 105; i++)
	{
		for (j = 0; j < 110; j++)digits[i][j] = 0;
	}
	while (getline(cin, y) && y != "0")
	{
		x = x + 1;
		c[x] = y.length();
		for (i = c[x]-1; i >= 0; i--)
		{
			digits[x][i] = y[i] - '0';
		}
	}
	p = -1;
	for (i = x; i >= 0; i--)
	{
		p = -1;
		for (j = c[i]-1; j >= 0; j--)
		{
			p = p + 1;
			sum[p] = digits[i][j] + sum[p];

		}
	}

	for (i = 0; i <306; i++)
	{
		if (sum[i] > 9)
		{
			sum[i + 1] += sum[i] / 10;
			sum[i] %= 10;
		}
		
	}
	for (k = 306; k >= 0; k--)
	{
		if (sum[k] != 0)
		{
			j = k;
			break;
		}
	}
	for (i = k; i >= 0; i--)cout << sum[i];
	cout << "\n";
	return 0;

}