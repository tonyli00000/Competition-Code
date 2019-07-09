#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int i, j, k,weight[210][210];
bool connected[210][210];
string roads[19900],line;

int min(int x, int y) {
	if (x < y)return x;
	else return y;
}
void find(int con) {
	int i, j, k;
	for (k = 0; k < con; k++) {
		for (i = 0; i < con; i++) {
			for (j = 0; j < con; j++) {
				if (min(weight[i][k], weight[k][j])>weight[i][j]) {
					weight[i][j] = min(weight[i][k], weight[k][j]);
				}
			}
		}
	}
}
int main()
{
	int t,l=1,city,road,pos,c=0;
	while (cin>>city>>road && city!=0) {
		int con = 0;
		for (i = 0; i < 200; i++) {
			for (j = 0; j < 200; j++) {
				connected[i][j] = false;
				weight[i][j] = 0;
			}
		}
		for (k = 0; k < road; k++) {
			cin >> line;
			for (i = 0; i < con; i++)if (roads[i] == line)break;
			if (i == con) {
				roads[con] = line;
				con++;
			}
			int a;
			for (i = 0; i < con; i++) {
				if (line == roads[i]) {
					a = i;
					break;
				}
			}
			cin >> line; 
			for (i = 0; i < con; i++)if (roads[i] == line)break;
			if (i == con) {
				roads[con] = line;
				con++;
			}
			int b;
			for (i = 0; i < con; i++) {
				if (line == roads[i]) {
					b = i;
					break;
				}
			}
			connected[a][b] = true; connected[b][a] = true;
			cin>>weight[a][b];
			weight[b][a] = weight[a][b];
		}
		find(con);
		cin >> line;
		int x, y;
		for (i = 0; i < con; i++) {
			if (line == roads[i]) {
				x = i;
				break;
			}
		}
		cin >> line;
		for (i = 0; i < con; i++) {
			if (line == roads[i]) {
				y = i;
				break;
			}
		}
		c++;
		cout << "Scenario #" << c << "\n";
		cout << weight[x][y]<<" tons\n";
		cout << "\n";
	}
	return 0;
}
