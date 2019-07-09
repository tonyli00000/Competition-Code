#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#define N 8
using namespace std;
int r[92][8], b = 0;
void solve(int step, int ans[N]){
	int i, j, k, row;
	for (i = 0; i < N; i++){
		ans[step] = i;
		for (row = 0; row < N; row++){
			if ((ans[row] == ans[step]) || (ans[row] + step - row == ans[step]) || (ans[row] - step + row == ans[step]))break;
		}
		if (row == step)solve(step + 1, ans);
	}
	if ((step == N)&&(b<92)){
		for (i = 0; i < N; i++){
			r[b][i] = ans[i];
		}
		b = b + 1;
	}
}
int main()
{
	int i, j, k, x, y, z, n, solution[N], s[92];
	string p;
	solve(0, solution);
	cin >> n;
	for (i = 0; i < n; i++){
		getline(cin, p);
		cin >> x >> y;
		//for (j = 0; j < 92; j++){
		//	for (k = 0; k < N; k++){
		//		if ((k + 1 == x) && (r[j][k] == y)){
		//			s[b] = j;
		//			b++;
		//		}
		//	}
		//}
		b = 0;
		for (j = 0; j < 92; j++)s[j] = 0;
		for (j = 0; j < 92; j++){
			if (r[j][y - 1] == x-1){
				s[b] = j;
				b++;
			}
		}
		cout << "SOLN       COLUMN" << "\n";
		cout << " #      1 2 3 4 5 6 7 8" << "\n";
		cout << "\n";
		for (z = 0; z < b; z++){
			if (z + 1>9)cout << z + 1 << "      ";
			else cout << " " << z + 1 << "      ";
			for (j = 0; j < N; j++){
				if (j < N - 1)cout << r[s[z]][j]+1 << " ";
				else cout << r[s[z]][j]+1 << "\n";
			}
		}
		if (i < n - 1)cout << "\n";
	
	}
	return 0;
}
