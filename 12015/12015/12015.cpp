#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int rel[105], i, j, k,t,c;
string temp[13];
int main()
{
	cin >> t;
	getline(cin, temp[0]);
	for (i = 0; i < 10; i++)rel[i] = 0;
	for (k = 0; k < t; k++){
		for (i = 0; i < 10; i++){
			getline(cin, temp[i]);
			c = temp[i].length();
			int x = 1, y = 1;
			while (temp[i][c - x] >= '0'&&temp[i][c - x] <= '9'){
				rel[i] += (temp[i][c - x] - '0')*y;
				x++;
				y++;
			}
			temp[i].erase(c - x, x - 1);
		}
		int largest = 0;
		for (i = 0; i < 10; i++){
			if (rel[i]>largest)largest = rel[i];
		}
		for (i = 0; i < 10; i++)if (rel[i] == largest)cout << temp[i] << "\n";
	}
	return 0;

}