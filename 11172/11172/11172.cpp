#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int i, j, k, t,a,b;
int main()
{
	cin >> t;
	for (i = 0; i < t; i++){
		cin >> a >> b;
		if (a - b>0)cout << ">\n";
		else if (a - b == 0)cout << "=\n";
		else cout << "<\n";
	}
	return 0;
}
