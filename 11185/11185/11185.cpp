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
	long long d, num;
	int rem, l, i;
	int s[1000];

	while (cin>>d && d>-1){
		num = d;
		l = 0;
		while (d>0){
			rem = d % 3;
			l = l + 1;
			d = d / 3;
		}
		for (i = 0; i<l; i++){
			rem = num % 3;
			s[i] = rem;
			num = num / 3;
		}
		if (l == 0)cout << "0\n";
		else {
			for (i = l - 1; i >= 0; i--)
				cout << s[i];
			cout << "\n";
		}
	}
	return 0;
}
