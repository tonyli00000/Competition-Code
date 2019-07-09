#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int a, b, c, d;
int main()
{
	while (cin >> a >> b >> c >> d){
		if ((a == 0) && (b == 0) && (c == 0) && (d == 0))break;
		cout << (((a + 40 - b) % 40)+ ((c + 40 - b) % 40) + ((c + 40 - d) % 40)) * 9 +1080<< "\n";
	}
	return 0;
}