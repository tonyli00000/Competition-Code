#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

#define MAXN 30

bool conn[MAXN][MAXN];
int id[MAXN];
int n;
int casenumber, caseid;

void search(int key, int idcount)
{
	int i;

	id[key] = idcount;
	for (i = 0; i < n; i++)
		if (conn[key][i] && id[i] == -1)
			search(i, idcount);
}

int main()
{
	string s;
	int i, j, idcount, a, b;

	cin >> casenumber;
	getline(cin, s);
	for (caseid = 1; caseid <= casenumber; caseid++)
	{
		while (getline(cin, s), s.length() == 0);
		n = s[0] - 'A' + 1;

		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++) conn[i][j] = false;

		while (getline(cin, s))
		{
			if (s.length() == 0) break;
			a = s[0] - 'A';
			b = s[1] - 'A';
			conn[a][b] = true;
			conn[b][a] = true;
		}

		for (i = 0; i < n; i++) id[i] = -1;
		
		idcount = 0;
		for (i = 0; i < n; i++)
			if (id[i] == -1) {
				idcount++;
				search(i, idcount);
			}

		if (caseid > 1) cout << "\n";
		cout << idcount << "\n";
	}

	return 0;
}