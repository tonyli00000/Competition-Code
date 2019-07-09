 /*
tonyli21
TASK:starry
LANG:C++11
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
#define MAXM 105

int d[2][8] = { { 0, -1, -1, -1, 0, 1, 1, 1 },
{ -1, -1, 0, 1, 1, 1, 0, -1 } };

struct Cluster{
	char s[MAXM][MAXM];
	int numst, high, wide;

	bool operator == (const Cluster &b){
		if (numst != b.numst) return false;

		if (high == b.high && wide == b.wide){
			bool flag;
			for (int i = 0; i < high; i++){
				flag = true;
				for (int j = 0; j < wide; j++){
					if (s[i][j] != b.s[i][j])
						flag = false;
						break;
					}
				if (!flag) break;
			}
			if (flag) return true;
			for (int i = 0; i < high; i++){
				flag = true;
				for (int j = 0; j < wide; j++){
					if (s[i][j] != b.s[high - i - 1][j]){
						flag = false;
						break;
					}
				}
				if (!flag) break;
			}
			if (flag) return true;
			for (int i = 0; i < high; i++){
				flag = true;
				for (int j = 0; j < wide; j++)
					if (s[i][j] != b.s[i][wide - j - 1]){
						flag = false;
						break;
					}
				if (!flag) break;
			}
			if (flag) return true;
			for (int i = 0; i < high; i++){
				flag = true;
				for (int j = 0; j < wide; j++)
					if (s[i][j] != b.s[high - i - 1][wide - j - 1]){
						flag = false;
						break;
					}
				if (!flag) break;
			}
			if (flag) return true;
		}

		if (high == b.wide && wide == b.high){
			bool flag;
			for (int i = 0; i < high; i++){
				flag = true;
				for (int j = 0; j < wide; j++)
					if (s[i][j] != b.s[wide - j - 1][i]){
						flag = false;
						break;
					}
				if (!flag) break;
			}
			if (flag) return true;
			for (int i = 0; i < high; i++){
				flag = true;
				for (int j = 0; j < wide; j++)
					if (s[i][j] != b.s[j][i]){
						flag = false;
						break;
					}
				if (!flag) break;
			}
			if (flag) return true;
			for (int i = 0; i < high; i++){
				flag = true;
				for (int j = 0; j < wide; j++)
					if (s[i][j] != b.s[j][high - i - 1]){
						flag = false;
						break;
					}
				if (!flag) break;
			}
			if (flag) return true;
			for (int i = 0; i < high; i++){
				flag = true;
				for (int j = 0; j < wide; j++)
					if (s[i][j] != b.s[wide - j - 1][high - i - 1]){
						flag = false;
						break;
					}
				if (!flag) break;
			}
			if (flag) return true;

		}
		return false;
	}

}clusters[30];

char g[MAXM][MAXM];
int h, w, mark[MAXM * MAXM], num[MAXM][MAXM], cnt1, cnt2;
int Left, Right, up, down;
bool vis[MAXM][MAXM];

Cluster create(){
	Cluster tmp;
	for (int i = 0; i < MAXM; i++){
		for (int j = 0; j < MAXM; j++){
			tmp.s[i][j] = 0;
		}
	}
	tmp.numst = 0;
	tmp.high = down - up + 1;
	tmp.wide = Right - Left + 1;
	for (int i = 0; i < tmp.high; i++){
		for (int j = 0; j < tmp.wide; j++){
			if (num[i + up][j + Left] == cnt1) tmp.s[i][j] = '1', tmp.numst++;
			else tmp.s[i][j] = '0';
		}
	}
	return tmp;
}

bool test(int x, int y)
{
	return 0 <= x && x < h && 0 <= y && y < w;
}

void floodfill(int x0, int y0){
	vis[x0][y0] = false;
	num[x0][y0] = cnt1;
	up = min(up, x0);
	down = max(down, x0);
	Left = min(Left, y0);
	Right = max(Right, y0);
	for (int i = 0; i < 8; i++){
		int x = x0 + d[0][i], y = y0 + d[1][i];
		if (test(x, y) && g[x][y] == '1' && vis[x][y]) floodfill(x, y);
	}
}

int main()
{
	freopen("starry.in", "r", stdin);
	freopen("starry.out", "w", stdout);
	cin >> w >> h;
	for (int i = 0; i < h; i++) 
		cin >> g[i];
	for (int i = 0; i < MAXM; i++){
		for (int j = 0; j < MAXM; j++){
			vis[i][j] = true;
			num[i][j] = 0;
		}
	}
	cnt1 = cnt2 = 0;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++){
			if (vis[i][j] && g[i][j] == '1'){
				cnt1++;
				up = down = i;
				Left = Right = j;
				floodfill(i, j);
				Cluster cl = create();
				bool flag = true;
				for (int k = 0; k < cnt2; k++){
					if (cl == clusters[k]){
						mark[cnt1] = k;
						flag = false;
						break;
					}
				}
				if (flag) clusters[mark[cnt1] = cnt2++] = cl;
			}
		}
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			if (g[i][j] != '0') cout << (char)(mark[num[i][j]] + 'a');
			else cout << "0";
		}
			cout << "\n";
	}
	return 0;
}