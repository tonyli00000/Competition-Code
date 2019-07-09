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
	int n, i, j, k, t = 0;
	while (cin >> n){
		vector<string>original,in(n),copy;
		for (i = 0; i < n; i++){
			cin >> original[i] >> in[i];
		}
		cout << "Pattern " << ++t << " was ";
		if (original == in)cout << "preserved.\n";
		copy = in;
		for (i = 1; i < 4; i++){
			for (j = 0; j < n; j++){
				string x="";
				for (k = n-1; k >=0; k--){
					x += in[k];
				}
				copy[j] = x;
			}
			in = copy;
			if (original == in)cout << "rotated " << i * 90 << " degrees.\n";
			for (j = 0; j < n; j++){
				for (k = 0; k < n; k++){
					copy[j][k] = copy[]
				}
			}
		}
	}
	return 0;
}
