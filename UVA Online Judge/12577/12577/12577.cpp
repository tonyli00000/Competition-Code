#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int main()
{
	string line;
	int p = 0;
	while (cin>>line && line!="*") {
		p++;
		cout << "Case " << p << ": ";
		if (line == "Hajj")cout << "Hajj-e-Akbar\n";
		else cout << "Hajj-e-Asghar\n";
	}
	return 0;
}
