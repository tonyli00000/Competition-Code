#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

string line;
int i, j, k;

int compare(string a, string b) {
	int i,con=0;
	for (i = 0; i < 3; i++) {
		if (a[i] != b[i])con++;
	}
	return con;
}
int main()
{
	int t;
	cin >> t;
	for (k = 0; k < t; k++) {
		cin >> line;
		if (line.length() == 5)cout << 3 << "\n";
		else {
			if(compare(line, "two")==1 || compare(line,"two")==0)cout<<2<<"\n";
			else cout << 1 << "\n";
		}
	}
	return 0;
}
