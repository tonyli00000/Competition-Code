#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>

using namespace std;
char big[500][500], small[500][500];
void rotate(int n) {
	char tmp[500][500];
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			tmp[i][j] = small[n - j - 1][i];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			small[i][j] = tmp[i][j];
	}
}
int main()
{
	int m, n,i,j,k;
	while (cin >> m >> n){
		if (!m && !n)break;
		for (i = 0; i < m; i++){
			for (j = 0; j < m; j++){
				cin >> big[i][j];
			}
		}
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				cin >> small[i][j];
			}
		}
		long a = 0, b = 0, c = 0, d = 0;
		for (i = 0; i + n <= m; i++){
			for (j = 0; j + n <= m; j++){
				bool b1=false,b2=false,b3=false,b4 = false;
				for (k = 0; k < n; k++){
					for (int l = 0; l < n; l++){
						if (small[k][l] != big[i + k][j + l])b1 = true;
						rotate(n);
						if (small[k][l] != big[i + k][j + l])b2 = true;
						rotate(n);
						if (small[k][l] != big[i + k][j + l])b3 = true;
						rotate(n);
						if (small[k][l] != big[i + k][j + l])b4 = true;
						rotate(n);
					}
				}
				a += !b1;
				b += !b2;
				c += !b3;
				d += !b4;
			}
		}
		cout << a << " " << b << " " << c << " " << d << "\n";
	}
	return 0;
}
