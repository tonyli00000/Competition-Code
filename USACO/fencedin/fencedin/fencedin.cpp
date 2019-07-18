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
#pragma warning(disable:4996)
using namespace std;

#define ll long long
using namespace std;
#define MAXN 25005

long long maxx,maxy, ct_x, ct_y;
vector<long long>xx(MAXN), yy(MAXN);


void Solve(){
	long long ct = 0, xi = 1, yi = 1, x = 0, y = 0;
	long long ans = 0;
	bool xfound = false, yfound = false;
	while (ct < ct_x * ct_y - 1){
		if (xx[xi] < yy[yi]){
			if (!yfound || !xfound){
				ct += ct_y - 1;
				ans += (ct_y - 1) * xx[xi];
			}
			else{
				ct += ct_y - x;
				ans += (ct_y - x) * xx[xi];
			}
			yfound = true;
			y++;
			xi++;
		}
		else{if (!xfound || !yfound){
				ct += ct_x - 1;
				ans += (ct_x - 1) * yy[yi];
			}
			else{
				ct += ct_x - y;
				ans += (ct_x - y) * yy[yi];
			}
			xfound = true;
			x++;
			yi++;
		}
	}
	cout << ans << "\n";
}


int main(){
	freopen("fencedin.in", "r", stdin);
	freopen("fencedin.out", "w", stdout);
	int i, j, k;
	cin >> maxx >> maxy >> ct_x>> ct_y;
	for (i = 1; i <= ct_x; i++)
		cin >> xx[i];

	sort(xx.begin() + 1, xx.begin() + ct_x + 1);
	xx[++ct_x] = maxx;
	for (int i = ct_x; i >= 1; i--)
		xx[i] -= xx[i - 1];
	sort(xx.begin() + 1, xx.begin() + ct_x + 1);
	for (int i = 1; i <= ct_y; i++)
		cin >> yy[i];
	sort(yy.begin() + 1, yy.begin() + ct_y + 1);
	yy[++ct_y] = maxy;

	for (int i = ct_y; i >= 1; i--)
		yy[i] = yy[i] - yy[i - 1];

	sort(yy.begin() + 1, yy.begin() + ct_y + 1);

	//  Check();

	Solve();
	return 0;
}