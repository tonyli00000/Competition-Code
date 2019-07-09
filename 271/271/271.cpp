#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
string input;
int i, j, k,len,x;
int main()
{
	while (getline(cin, input)){
		x = 0;
		len = input.length();
		for (i = len - 1; i >= 0; i--){
			if ((input[i] >= 'p') && (input[i] <= 'z'))x++;
			else if ((input[i] == 'C') || (input[i] == 'D') || (input[i] == 'E') ||(input[i] == 'I')){
				if (x >= 2)x--;
				else{
					x = 0;
					break;
				}
			}
			else if (input[i] == 'N'){
				if (x > 1){
					x = 0;
					break;
				}
			}
		}
		if (x == 1)cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
