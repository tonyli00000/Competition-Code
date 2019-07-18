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
	int a, b, c, d, L, i, j, k, f;
	while (cin >> a >> b >> c >> d >> L) {
		if (a == 0 && b == 0 && c == 0 && d == 0 && L == 0)break;
		k = 0;
		for (i = 0; i <= L; i++){
			f = (i*i*a) + (i*b) + c;
			if (f%d == 0)
				k++;
		}
		cout << k << "\n";
	}
    return 0;
}

