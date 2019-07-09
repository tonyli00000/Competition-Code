#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
#define N 8
void solve(int step, int ans[N])
{
	int i, j, k, b = 0;
	bool x[N][N];
	if (step == 0){
		ans[0] = 0;
		for (i = 0; i < N; i++){
			x[0][i] = false;
			x[i][0] = false;
			x[i][i] = false;
		}
	}
	else {
		i = 0;
		while (i < N){
			for (j = 0; j < step; j++){
				if (x[step][j] == true){
					ans[step] = i;
					for (k = 0; i < N; i++){
						x[step][i] = false;
						x[i][k] = false;
						x[k][k] = false;
					}
					break;
				}
				if (j == step - 1){
					for (i = 0; i < N; i++){
						for (j = 0; j < N; j++){
							x[i][j] = true;
							step = 0;
							b = b + 1;
						}
					}
				}
			}
			
		}
	}

	if (step == N){
		for (i = 0; i < N; i++)cout << ans[i];
		cout << "\n";
		return;
	}
}

int main()
{
	int solution[N];
	
	solve(0, solution);
	return 0;
}
