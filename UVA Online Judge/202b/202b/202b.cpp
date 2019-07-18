
#include <iostream>
#include <string>
using namespace std;
#define MAXN 10000
int a, b, i, j, pos;
int r[MAXN];                    // remainder after every cycle
int digits[MAXN];               // digits after every cycle
int appeared[MAXN];                     // whether the remainder has appeared before; if so, at which position
int main()
{
	while (cin >> a >> b)
	{
		// initialization
		for (i = 0; i < b; i++)
		{
			r[i] = 0;
			appeared[i] = -1;
		}
		cout << a << "/" << b << " = " << a / b << ".";
		a = a % b;
		pos = 0;
		while (appeared[a] == -1)
		{
			appeared[a] = pos;
			r[pos] = a;
			digits[pos] = (a * 10) / b;
			a = (a * 10) % b;
			pos++;
		}
		for (i = 0; i < appeared[a]; i++) cout << digits[i];            // print out all digits before cycle
		cout << "(";
		for (i = appeared[a]; i < pos; i++)
		{
			if (i == 50)
			{
				cout << "...";
				break;
			}
			cout << digits[i];
		}
		cout << ")\n";
		cout << "   " << pos - appeared[a] << " = number of digits in repeating cycle\n\n";
	}
	return 0;
}
