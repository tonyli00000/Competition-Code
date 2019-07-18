#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
using namespace std;
//int q[92][8],x,y,b=0,ans[N],z;
//void queen(int step, int ans[N], int x, int y){
//	int i, j, k, row, b = 0;
//		for (i = 0; i < x-1; i++){
//			ans[step] = i;
//			for (row = 0; row < step; row++)if ((ans[row] == ans[step]) || (ans[row] + step - row == ans[step]) || (ans[row] - step + row == ans[step]))break;
//			if (row == step){
//				b++;
//				queen(step + 1, ans, x, y);
//			}
//		}
//		if (i == N)queen(step + 1, ans, x, y);
//	if (step<y-1)queen(step + 1, ans, x, y);
//	if (step == y){
//		if (b > z){
//			z = b;
//			b = 0;
//		}
//
//	}
//}

int main()
{
	int i, j, k,x,y,b;
	char c;

	cin >> b;
	for (i = 0; i < b;i++){
		cin >> c >> x >> y;
		if ((c == 'Q')||(c=='r')){
			if (x >= y)cout << y << "\n";
			else cout << x << "\n";
		}
		if (c == 'K')cout << (((x + 1) / 2)*((y + 1) / 2)) << "\n";
		if (c == 'k')cout << ((x*y + 1) / 2) << "\n";
	}
	return 0;
}
