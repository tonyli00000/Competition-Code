#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#define MAXN 100000
using namespace std;

int a, b, c, d,t, i, j, k, data[4],state[MAXN][4],tail;

void solve(int a, int b, int c, int d){
	int a2, b2, c2, d2,i,j,k;

	for (i = 0; i < 3; i++){
		if (data[i] != 0){
			for (j = 0; j < 3; j++){
				if (j != i){
					data[j] += data[i];
					if (data[j]>a){
						data[i] = data[j] - a;
						data[j] = a;
						
					}
					else{
						data[i] = data[i] - data[j];
					}
				}
			}
		}
	}
}
int main()
{
	cin >> t;
	for (i = 0; i < t; i++){
		data[3] = 0;
		cin >> a >> b >> c >> d;
		data[0] = a;
		data[1] = b;
		data[2] = c;
		data[3] = 0;
		if (c == d)cout << 0 << " " << d << "\n";
		else{
			if (c < d)cout << 0 << " " << c << "\n";
			else{
				tail = 0;
				solve(a, b, c, d);
			}
		}
	}
	return 0;
}
