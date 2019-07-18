#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#define N 8
using namespace std;
int i, j, k, n = 0 , s[8], r[92][8], t;
void solve(int step, int ans[N]){
	int i, j, k, row;
	for (i = 0; i < N; i++){
		ans[step] = i;
		for (row = 0; row < step; row++){
			if ((ans[row] == ans[step]) || (ans[row] + step - row == ans[step]) || (ans[row] - step + row == ans[step]))break;
		}
		if (row == step)solve(step + 1, ans);
	}
	if ((step == N)&&(n<92)){
		for (i = 0; i < N; i++){
			r[n][i] = ans[i];
		}
		n++;
	}
}
int main()
{
	int solution[N],b;
	solve(0, solution);
	b = 1;
	while (cin >> s[0]){
		s[0]--;
		for (i = 1; i < N; i++){
			cin >> s[i];
			s[i]--;
		}

		for (i = 0; i < 92; i++){
			t = 0;
			for (j = 0; j < N; j++){
				if (r[i][j] != s[j])t++;
			}
			if (i == 0)k = t;
			else if (t < k)k = t;
		}
		cout << "Case " << b << ": " << k<<"\n";
		b++;
	}
	return 0;
}
