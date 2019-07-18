#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
using namespace std;
#define MAXN 30
string s;
int connected[MAXN][MAXN];                              // connectivity
int top[MAXN], neighbor[MAXN][MAXN];    // list of neighbors
int total;                                                              // total # of nodes
int order[MAXN];                                                // position of letter i in the order
int path[MAXN];                                                 // letter of position i
int solution[MAXN], minbandwidth;
void solve(int step, int last)
{
	int i, j, maxx, dist;
	int a, b, thisone;
	if (step == total) {
		// calculate bandwidth of the solution
		maxx = 0;
		for (i = 0; i < total; i++)
		{
			a = path[i];
			// calculate bandwidth of pos i
			for (j = 0; j < top[a]; j++) {
				b = neighbor[a][j];
				dist = abs(order[a] - order[b]);
				if (dist > maxx) maxx = dist;
			}
		}
		//for (i = 0; i < total; i++) cout << char('A' + solution[i]) << " ";
		//cout << "-> " << maxx << "\n";
		if (maxx < minbandwidth) {
			// copy solution
			minbandwidth = maxx;
			for (i = 0; i < total; i++) solution[i] = path[i];
		}
		return;
	}
	if (step == 0) {
		for (i = 0; i < MAXN; i++)
			if (top[i] > 0) {
				order[i] = step;
				path[step] = i;
				solve(step + 1, i);
				order[i] = -1;
			}
	}
	else {
		for (i = 0; i < MAXN; i++) {
			if ((top[i] > 0) && (order[i] == -1)) {
				order[i] = step;
				path[step] = i;
				solve(step + 1, i);
				order[i] = -1;
			}
		}
	}
}
void addedge(int start, int finish)
{
	int i;
	for (i = 0; i < top[start]; i++)
		if (neighbor[start][i] == finish) return;
	connected[start][finish] = 1;
	neighbor[start][top[start]] = finish;
	top[start]++;
}
int main()
{
	int i, j, k, tmp, pos, start, thisone;
	while (getline(cin, s), s != "#")
	{
		// initialize
		for (i = 0; i < MAXN; i++)
			for (j = 0; j < MAXN; j++) connected[i][j] = 0;
		for (i = 0; i < MAXN; i++) {
			order[i] = -1;
			top[i] = 0;
		}
		// process inputs
		s = s + ";";
		pos = 0;
		while (pos < s.length())
		{
			start = s[pos] - 'A';
			pos += 2;
			while (s[pos] != ';')
			{
				thisone = s[pos] - 'A';
				addedge(start, thisone);
				addedge(thisone, start);
				pos++;
			}
			pos++;
		}
		total = 0;
		for (i = 0; i < MAXN; i++)
			if (top[i] > 0) total++;
		// sort neighbors
		for (i = 0; i < MAXN; i++)
			for (j = 0; j < top[i]; j++)
				for (k = j + 1; k < top[i]; k++)
					if (neighbor[i][j] > neighbor[i][k]) {
						tmp = neighbor[i][j];
						neighbor[i][j] = neighbor[i][k];
						neighbor[i][k] = tmp;
					}
		// solving
		minbandwidth = 10000;
		solve(0, -1);
		// print answer
		for (i = 0; i < total; i++) cout << char('A' + solution[i]) << " ";
		cout << "-> " << minbandwidth << "\n";
	}
	return 0;
}
