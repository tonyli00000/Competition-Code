#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

string arr[6] = { "HELLO", "HOLA", "HALLO", "BONJOUR", "CIAO", "ZDRAVSTVUJTE" };
string b[6] = { "ENGLISH","SPANISH","GERMAN","FRENCH","ITALIAN","RUSSIAN" };
int main()
{
	string temp;
	int c = 0,i,j,k;
	while (cin >> temp && temp != "#") {
		c++;
		cout << "Case " << c << ": ";
		for (i = 0; i < 6; i++) {
			if (arr[i] == temp) {
				cout << b[i] << "\n";
				break;
			}
		}
		if (i == 6)cout << "UNKNOWN\n";
	}
	return 0;
}
