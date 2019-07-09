#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

#define MAXN 205
#define MAXSTATE (MAXN * MAXN)
#define BIGNUMBER 100000000

int casenumber;
int a, b, c, d;
int limit[3];
long queue[MAXSTATE][4], first, last;           // water in a, b, c, and the water poured
bool reached[MAXN][MAXN];                                       // whether state of (a, b, xx) is reached. xx is unimportant because total water is fixed
long best[MAXN];

void add_state(int aa, int bb, int cc, long dd)
{
	long p;

	if (reached[aa][bb]) return;
	reached[aa][bb] = true;

	p = last;
	while (queue[p][3] > dd) {
		queue[p + 1][0] = queue[p][0];
		queue[p + 1][1] = queue[p][1];
		queue[p + 1][2] = queue[p][2];
		queue[p + 1][3] = queue[p][3];
		p--;
	}
	p++;
	queue[p][0] = aa;
	queue[p][1] = bb;
	queue[p][2] = cc;
	queue[p][3] = dd;

	last++;

	if (best[aa] > dd) best[aa] = dd;
	if (best[bb] > dd) best[bb] = dd;
	if (best[cc] > dd) best[cc] = dd;
}

int main()
{
	int i, j, p;
	int new_state[3];
	long dd;

	cin >> casenumber;
	while (casenumber > 0) {
		casenumber--;
		cin >> a >> b >> c >> d;

		limit[0] = a;
		limit[1] = b;
		limit[2] = c;

		first = 0;
		last = 0;
		queue[0][0] = 0; queue[0][1] = 0; queue[0][2] = c; queue[0][3] = 0;
		for (i = 0; i <= a; i++)
			for (j = 0; j <= b; j++) reached[i][j] = false;
		reached[0][0] = true;
		for (i = 0; i < MAXN; i++) best[i] = BIGNUMBER;
		best[0] = 0; best[c] = 0;

		while (first <= last) {
			for (i = 0; i < 3; i++) {
				for (j = 0; j < 3; j++)
					if ((i != j) && ((queue[first][i] > 0) && (queue[first][j] < limit[j]))) {
						new_state[0] = queue[first][0];
						new_state[1] = queue[first][1];
						new_state[2] = queue[first][2];

						if (queue[first][i] < limit[j] - queue[first][j]) {
							new_state[i] = 0;
							new_state[j] += queue[first][i];
							add_state(new_state[0], new_state[1], new_state[2], queue[first][3] + queue[first][i]);
						}
						else {
							new_state[i] -= limit[j] - queue[first][j];
							new_state[j] = limit[j];
							add_state(new_state[0], new_state[1], new_state[2], queue[first][3] + (limit[j] - queue[first][j]));
						}
					}
			}
			first++;
		}

		p = d;
		while (best[p] == BIGNUMBER) p--;
		cout << best[p] << " " << p << "\n";
	}
	return 0;
}

