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

int main()
{
	int i, j, k;
	for (k = 0; k < 10; k++){
		string line;
		getline(cin, line);
		for (j = 0; j < line.length(); j++){
			if (line[j] == ',')line[j] = ' ';
		}
		stringstream ss(line);
		int x, y, z,a,b,ans=0;
		ss >> x >> y >> z;
		for (i = 0;; i++){
			if (pow(x, i) > 99999){
				a = i;
				break;
			}
		}
		for (i = 0;; i++){
			if (pow(y, i) > 99999){
				b = i;
				break;
			}
		}
		for (i = 0; i < a; i++){
			for (j = 0; j < b; j++){
				long long num = pow(x, i)*pow(y, j);
				if (num > 99999)break;
				if (num >= 10000){
					while (num){
						ans += (num%10 == z);
						num /= 10;
					}
				}
				
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
