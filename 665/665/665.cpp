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
	int t, i, j, k;
	cin >> t;
	for (k = 0; k < t; k++){
		if (k != 0)cout << "\n";
		int m, n;
		cin >> m >> n;
		vector<bool>coin(m, true);
		for (i = 0; i < n; i++){
			int x;
			cin >> x;
			vector<int>in;
			for (j = 0; j < x*2; j++){
				int y;
				cin >> y;
				y--;
				in.push_back(y);
			}
			char c;
			cin >> c;
			if (c == '='){
				for (j = 0; j < in.size(); j++){
					coin[in[j]] = false;
				}
			}
		}
		bool found = false;
		int c = -1;
		for (i = 0; i < coin.size(); i++){
			if (coin[i] && found)break;
			if (coin[i]){
				found = true;
				c = i;
			}
		}
		if (i != coin.size()||!found)cout << 0 << "\n";
		else cout << c + 1 << "\n";
	}
	return 0;
}
