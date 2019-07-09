#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int i, j, k, t, a[10],b=0,c=0;
bool flag = true;
int main()
{
	cin >> t;
	cout << "Lumberjacks:\n";
	for (i = 0; i < t; i++){
		c = 0;
		b = 0;
		flag = true;
		for (j = 0; j < 10; j++)cin >> a[j];
		for (j = 0; j < 9; j++){
			if (j == 0){
				if (a[j + 1] < a[j])c = 0;
				else c = 1;
			}
			else {
				if (a[j + 1] < a[j])b = 0;
				else b = 1;
				if (c != b){
					flag = false;
					break;
				}
			}
		}
		if (flag == true)cout << "Ordered\n";
		else cout << "Unordered\n";
	}
	return 0;
}
