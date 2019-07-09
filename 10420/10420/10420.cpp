#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int i, j, k, t, n, a, b=0, c;
string y;
string x[80];
bool flag = false;
int main()
{
	cin >> t;
	getline(cin, y);
	for (k = 0; k < t; k++){
		getline(cin, y);
		for (i = 0; i < b; i++){
			if (x[i] == y){
				flag = false;
				break;
			}
		}
		if (i == b){
			x[b] = y;
			b++;
		}
	}
	return 0;
}
