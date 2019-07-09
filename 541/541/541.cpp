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
	int i, j, bit, n, m[200][200], a, b, c, d, e, f;
	while (cin>>n && n){
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				cin >> m[i][j];

		e = 0;
		f = 0;
		for (i = 1; i <= n; i++){
			a = 0;
			for (j = 1; j <= n; j++){
				a = a + m[i][j];
			}
			if (a % 2 != 0){
				c = i;
				e++;
			}
		}
		for (j = 1; j <= n; j++){
			b = 0;
			for (i = 1; i <= n; i++){
				b = b + m[i][j];
			}
			if (b % 2 != 0){
				d = j;
				f++;
			}
		}
		if (e == 0 && f == 0)cout << "OK\n";
		else if (e == 1 && f == 1)cout << "Change bit (" << c << "," << d << ")\n";
		else cout<<"Corrupt\n";
	}
	return 0;
}