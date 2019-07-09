#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int m, n;

bool visited[102][102],letters[30];
int matrix[102][102];
bool flag = true;

 #define WAYS 4
 int xx[4] = { 1, 0, 0, -1 };
 int yy[4] = { 0, 1, -1, 0 };


void search(int x, int y, int eid,int p)
{
	int i;
	for (i = 0; i < WAYS; i++)
		if ((matrix[x + xx[i]][y + yy[i]] == p) && (x + xx[i] >= 0) && (y + yy[i] >= 0) && (x + xx[i]<m) && (y + yy[i]<n))
			search(x + xx[i], y + yy[i], eid,p);
}

int main()
{
	int i, j, k, counter, t = 1,index=0,l[30],r[30];
	char c;
	cin >> t;
	for(k=0;k<t;k++){
		for (i = 0; i < 26; i++){
			letters[i] = 0;
			r[i] = 0;
		}
		cout << "World #" << k + 1 << "\n";
		cin >> m >> n;
		for (i = 0; i < m; i++){
			for (j = 0; j < n; j++){
				cin >> c;
				if (letters[c - 'a'] == 0){
					matrix[i][j] = c - 'a';
					letters[c - 'a'] = 1;
				}
				else matrix[i][j] = c-'a';
			}
		}
		counter = 0;
		int q = 0;
		for (i = 0; i < m; i++){
			for (j = 0; j < n; j++){
				if (letters[matrix[i][j]]== 1){
					if (flag == true){
						counter++;
						r[matrix[i][j]]++;
						flag = false;
					}
					search(i, j, counter,matrix[i][j]);
					flag = true;
					letters[matrix[i][j]] = 0;
				}
				counter = 0;
			}
		}
		int temp;
		for (i = 0; i < 26; i++){
			for (j = i; j < 26; j++){
				if ((r[j] >= r[i]) && (r[j] != 0) && (r[i] != 0)){
					temp = r[i];
					r[i] = r[j];
					r[j] = temp;
				}
			}
		}
		for (i = 0; i < 26; i++)if (r[i] != 0)cout <<char(i+'a')<<": "<< r[i] << "\n";
		t++;
	}

	return 0;
}
