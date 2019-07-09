#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int i, j, k, x, y, z, s[1002],b;
int main()
{
	while (cin >> x){
		if ((x % 6 == 2)&&(x!=2)){
			b = 1;
			for (i = 0; i <= x/2-1; i++){
				s[i] = 2 * b;
				b++;
			}
			s[i] = 3;
			s[i+1] = 1;
			b = 3;
			for (j = i + 2; j < x - 1; j++){
				s[j] = 1 + 2 * b;
				b++;
			}
			s[j] = 5;
		}
		if ((x % 6 == 3) && (x != 3)){
			b = 2;
			for (i = 0; i <= x / 2-2; i++){
				s[i] = 2 * b;
				b++;
			}
			s[i] = 2;
			b = 2;
			for (j = i + 1; j <= x - 3; j++){
				s[j] = 1 + 2 * b;
				b++;
			}
			s[j] = 1;
			s[j + 1] = 3;
		}
		if ((x % 6 != 2) && (x % 6 != 3)){
			b = 1;
			for (i = 0; i < x / 2; i++){
				s[i] = 2 * b;
				b++;
			}
			b = 0;
			for (i = x / 2; i < x; i++){
				s[i] = 1 + 2 * b;
				b++;
			}
		}
		if ((x == 2) || (x == 3))cout << "Impossible" << "\n";
		else if (x == 1)cout << 1 << "\n";
		else{
			for (i = 0; i < x - 1; i++){
				cout << s[i] << " ";
				s[i] = 0;
			}
			cout << s[x - 1] << "\n";
			s[x - 1] = 0;
		}
	}
	return 0;
}
