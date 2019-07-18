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

using namespace std;

int xx[] = { -1, 0, 0, 1 };
int yy[] = { 0,-1, 1, 0 };

string ar[32];
char mark = '#';

void dfs(int j, int k);

int main()

{
	int i, j, k, l, t;

	bool a = true;
	while(a){
		i = 0;
		while (getline(cin,ar[i]))
		{
			if (ar[i][0] == '_')
				break;
			i++;
		}
		for (j = 0; j <= i; j++)
		{
			l = ar[j].length();
			for (k = 0; k<l; k++)
			{
				if (ar[j][k] != ' ' && ar[j][k] != '_' &&  ar[j][k] != 'X')
				{
					mark = ar[j][k];
					ar[j][k] = mark;
					dfs(j, k);
				}
			}
		}
		for (j = 0; j <= i; j++)cout << ar[j] << "\n";
	}
	return 0;
}

void dfs(int j, int k)
{

	int a, x, y;

	for (a = 0; a<4; a++)
	{
		x = j + xx[a];
		y = k + yy[a];

		if (ar[x][y] == ' ')
		{
			ar[x][y] = mark;
			dfs(x, y);

		}
	}
	return;
}
