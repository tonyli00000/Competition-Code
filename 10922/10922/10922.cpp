#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int digits[10];
int i, j, k;
string line;
void p(int num, int a[10])
{
	int i, j, k;
	int factor = 1;
	int temp = num;
	while (num != 0)
	{
		for (i = 0; i<num % 10; i++)a[i] += factor;
		for (i = 0; i<10; i++)a[i] += factor*(num / 10);
		a[0] -= factor;
		a[num % 10] += (temp%factor) + 1;
		factor *= 10;
		num /= 10;
	}
}
int main()
{
	int m, n;
	while (cin >> m >> n) {
		if (m == 0 && n == 0)break;
		for (i = 0; i < 10; i++)digits[i] = 0;
		p(m - 1, digits);
		for (i = 0; i < 10; i++)digits[i] *= -1;
		p(n, digits);
		for (i = 0; i < 9; i++)cout << digits[i] << " ";
		cout << digits[9] << "\n";
	}
	return 0;
}
