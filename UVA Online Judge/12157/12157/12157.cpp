#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int main()
{
	int i, j, k;
	int t;
	cin >> t;
	for (k = 0; k < t;k++) {
		cout << "Case " << k + 1 << ": ";
		int a;
		cin >> a;
		int c=0,d=0;
		for (i = 0; i < a; i++) {
			int time;
			cin >> time;
			c += time / 60+1;
			d += time / 30+1;
		}
		if (d * 10 < c * 15)cout << "Mile "<<d*10<<"\n";
		else {
			if (c * 15 < d * 10)cout << "Juice " << c * 15 << "\n";
			else cout << "Mile Juice " << c * 15 << "\n";
		}
	}
	return 0;
}
