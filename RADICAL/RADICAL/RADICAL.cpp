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

using namespace std;

int main()
{
	int i, j, k;
	for (k = 0; k < 5; k++){
		string line;
		getline(cin, line);
		stringstream ss(line);
		int x, y, z;
		ss >> x >> y >> z;
		bool real = !(z < 0);
		z = abs(z);
		if (y == 0 || z == 0){
			cout << x << ", " << y << ", " << z << "\n";
			continue;
		}
		int div = 1;
		for (i = 2; pow(i, 2) <= z; i++){
			int a = pow(i, 2);
			if (z%a == 0)div = i;
		}
		y *= div;
		z /= (div*div);
		if (z == 1){
			x += y;
			y = 0;
			z = 0;
		}
		if (!real)cout << x << ", " << y << "i, " << z<<"\n";
		else cout << x << ", " << y << ", " << z << "\n";
	}
	return 0;
}
