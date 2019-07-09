#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char a[110][110];
string ans;
int dr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dc[] = { 1, 1, 1, 0, 0, -1, -1, -1 };

bool found(int i, int j, int &i1, int &j1){
	int p, q, r;
	for (int k = 0; k<8; k++){
		for (p = i, q = j, r = 0; ans[r] != '\0'; r++){
			if (a[p][q] == ans[r]){
				p += dr[k];
				q += dc[k];
			}
			else break;
		}
		if (ans[r] == '\0'){
			i1 = p - dr[k]; j1 = q - dc[k];
			return 1;
		}
	}
	return 0;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		int i, j, i1, j1;
		bool flag = false;
		for (i = 0; i < n; i++){
			for (j = 0; j < m; j++){
				cin >> a[i][j];
			}
		}
		cin >> m;
		while (m--){
			cin >> ans;
			flag = false;
			for (i = 0; i < n; i++){
				for (j = 0; j < n; j++){
					if (a[i][j] == ans[0]){
						if (found(i, j, i1, j1)){
							cout << i + 1 << "," << j + 1 << "\n";
							flag = true; 
						}
					}
					if (flag) break;
				}
				if (flag) break;
			}
			if (!flag) cout << "Not found\n";
		}
	}
	return 0;
}