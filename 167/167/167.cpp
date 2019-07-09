#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
#define N 8

int t, n, i, x[8][8], sum, z;
void solve(int step, int ans[N]){
	int i, j, k, row;
	for (i = 0; i < N; i++) {
		ans[step] = i;
		for (row = 0; row < step; row++)
			if ((ans[row] == ans[step]) || (ans[row] + step - row == ans[step]) || (ans[row] - step + row == ans[step]))break;
		if (row == step) solve(step + 1, ans);
	}
	sum = 0;
	if (step == N){
		for (i = 0; i < N; i++){
			sum = sum + x[i][ans[i]];
		}
		if (sum>z)z = sum;
		sum = 0;
		t = t + 1;
	}
}

int main()
{
	int solution[N],j,k;
	cin >> n;
	for (i = 0; i < n; i++){
		for (j = 0; j < 8; j++){
			for (k = 0; k < 8; k++){
				cin >> x[j][k];
			}
		}
		z = 0;
		solve(0, solution);
		cout << fixed << setw(5) << right << z << "\n";
	} 
	return 0;
}
