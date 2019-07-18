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
#define MAXP (long)sqrt(2000000000)+10

using namespace std;
long long humble[5845];

void genHumble()
{
	register int a, b, c, d, i;
	register long w, x, y, z;

	humble[1] = a = b = c = d = 1;

	for (i = 2; i<5843; i++)
	{
		w = 2 * humble[a];
		x = 3 * humble[b];
		y = 5 * humble[c];
		z = 7 * humble[d];

		humble[i] = min(min(w, x), min(y, z));

		if (humble[i] == w)a++;
		if (humble[i] == x)b++;
		if (humble[i] == y)c++;
		if (humble[i] == z)d++;
	}
}
int main()
{
	genHumble();
	int n;
	while (cin >> n) {
		if ((n % 100) / 10 == 1)
		{
			printf("The %dth humble number is %d.\n", n, humble[n]);
			continue;
		}
		cout << "The ";
		if (n > 9)cout << n / 10;
		int a = n % 10;
		
		if (a == 1)cout << "1st ";
		else {
			if (a == 2)cout << "2nd ";
			else {
				if (a == 3)cout << "3rd ";
				else cout << a << "th ";
			}
		}
		cout << "humble number is " << humble[n] << ".\n";
	}
	return 0;
}
