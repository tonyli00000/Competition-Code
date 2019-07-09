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
int i, j, k;
string spotted[505], plain[505];

int main()
{
	int n, m;
	cin >> n >> m;
	for (i = 0; i < n; i++){
		cin >> plain[i];
	}
	for (i = 0; i < n; i++){
		cin >> spotted[i];
	}
	int minn = 10000;
	int lo = 0, hi = m-1, mid;
	while (lo<hi){
		mid = lo + (hi - lo) / 2;
		bool solved = false;
		for (i = 0; i < m - mid; i++){
			j = i + mid;
			string x[505], y[505];
			string a = "", b = "";
			for (int l = 0; l < n; l++){
				for (k = i; k <= j; k++){
					a += plain[l][k];
					b += spotted[l][k];
				}
				x[l] = a;
				y[l] = b;
				a = "";
				b = "";
			}
			vector<string>v(505);
			sort(x, x+n);
			sort(y,y+n);

			auto it = set_intersection(x, x+n, y, y+n, v.begin());
			v.resize(it - v.begin());

			if (v.size() == 0){
				solved = true;
				break;
			}
		}
		if (solved){
			minn = min(minn, mid);
			hi = mid;
		}
		else {
			lo = mid+1;
		}
	}

	cout << minn+1 << "\n";
	return 0;
}
