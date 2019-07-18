#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int i, j, k, x, y, m, n, t;
int main()
{
	while (cin >> t&&t > 0){
		cin >> m >> n;
		for (i = 0; i < t; i++){
			cin >> x >> y;
			x = x - m;
			y = y - n;
			if (x>0 && y > 0)cout << "NE\n";
			else if (x < 0 && y>0)cout << "NO\n";
			else if (x < 0 && y < 0)cout << "SO\n";
			else if (x>0 && y < 0)cout << "SE\n";
			else cout << "divisa\n";
		}
	}
	return 0;
}
