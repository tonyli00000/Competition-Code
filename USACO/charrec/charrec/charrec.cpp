/*
ID: tonyli21
PROG: charrec
LANG: C++11
*/
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

#define N 30  
#define M 1210  
#define flag 120  

char mat[N][N][N], in[M][N], ans[M];
int f[M][N][3], g[M][N][N], dp[M], from[M], key[M];

//f[i][j][k]=Difference for all cases at line i for character j;
//dp[i]=minimum error at line i;
int n;

int main()
{
	int i, j, k, x, y, ff, tmp;
	cin >> n;
	for (i = 0; i <= 26; i++){
		for (j = 0; j < 20; j++){
			cin >>mat[i][j];
		}
	}
	cin >> n;
	for (i = 0; i < n; i++) cin >> in[i];
	for (i = 0; i<n; i++){
		for (j = 0; j <= 26; j++){
			for (k = 0; k<20; k++){
				tmp = 0;
				for (x = 0; x<20; x++){
					if (mat[j][k][x] != in[i][x]) tmp++;
				}
				g[i][j][k] = tmp;
			}
		}
	}
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			for (int k = 0; k < 3; k++){
				f[i][j][k] = -1;
			}
		}
	}

	//Preprocessing to find f;
	for (i = 0; i<n; i++){
		for (j = 0; j <= 26; j++){
			if (i + 19<n){ //normal  
				tmp = 0;
				for (x = 0; x < 20; x++) {
					tmp += g[i + x][j][x];
				}
				if (tmp <= flag) f[i][j][1] = tmp;
			}
			if (i + 20<n){ //greater
				for (k = 0; k<20; k++){
					tmp = 0;
					for (x = 0; x<20; x++){
						ff = i + x;
						if (x>k) ff++;
						tmp += g[ff][j][x];
					}
					if (tmp <= flag && (f[i][j][2] == -1 || tmp<f[i][j][2])) f[i][j][2] = tmp;
				}
			}
			if (i + 18<n){ //lesser  
				for (k = 0; k<20; k++){
					tmp = 0;
					for (x = 0; x<20; x++){
						if (x == k) continue;
						ff = i + x;
						if (x>k) ff--;
						tmp += g[ff][j][x];
					}
					if (tmp <= flag && (f[i][j][0] == -1 || tmp<f[i][j][0])) f[i][j][0] = tmp;
				}
			}
		}
		f[i][27][0] = f[i][27][1] = f[i][27][2] = flag + 10;
	}
	for (int i = 0; i < M; i++){
		dp[i] = -1;
	}
	dp[0] = 0;
	for (i = 0; i<n; i++){
		if (dp[i] != -1){
			for (j = 0; j <= 27; j++){
				for (k = 0; k <= 2; k++){
					if (f[i][j][k] != -1){
						if (dp[i + k + 19] == -1 || dp[i + k + 19]>dp[i] + f[i][j][k]){
							dp[i + k + 19] = dp[i] + f[i][j][k];
							from[i + k + 19] = i;
							key[i + k + 19] = j;
						}
					}
				}
			}
		}
	}
	for (i = n, j = 0; i; i = from[i], j++){
		if (!key[i]) ans[j] = ' ';
		else if (key[i] == 27) ans[j] = '?';
		else ans[j] = 'a' + key[i] - 1;
	}
	for (i = j - 1; i >= 0; i--) cout << ans[i];
	cout << "\n";
	return 0;
}