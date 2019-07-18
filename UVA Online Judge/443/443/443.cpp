#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
long long i, j, k, x, y, z, t, h[5844], a, b, c, d, g,N;
int main()
{
	h[0] = 1;
	g = 1;
	x = 2;
	y = 3;
	z = 5;
	t = 7;
	while (g < 5842)
	{
		for (i = 0; i < 30; i++);
	}
	while (cin >> N)
	{
		if (N == 0) break;

		else if (N % 10 == 1){
			cout << "The " << N << "st humble number is " << h[N] << "." << "\n";
		}
		else 
			if (N % 10 == 2){
			cout << "The " << N << "nd humble number is " << h[N] << "." << "\n";
		}
		else
			if (N % 10 == 3)cout << "The " << N << "rd humble number is " << h[N] << "." << "\n";
			else cout << "The " << N << "th humble number is " << h[N] << "." << "\n";
		
	}
	return 0;
}
