#include <iostream>
#include <string>

using namespace std;

#define MAXN 300

int n, block[MAXN], stack[MAXN][MAXN], depth[MAXN];

void push(int n, int col)
{
	block[n] = col;
	stack[col][depth[col]] = n;
	depth[col]++;
}

void printstack()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		cout << i << ":";
		for (j = 0; j < depth[i]; j++) cout << " " << stack[i][j];
		cout << "\n";
	}

}

int main()
{
	int i, a, b, cola, colb, posa, posb;
	string s, ss;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		block[i] = i;
		depth[i] = 1;
		stack[i][0] = i;
	}

	while (cin >> s, s != "quit")
	{
		cin >> a >> ss >> b;
		cola = block[a];
		for (i = 0; i < depth[cola]; i++)
			if (stack[cola][i] == a) posa = i;
		colb = block[b];
		for (i = 0; i < depth[colb]; i++)
			if (stack[colb][i] == b) posb = i;

		if (cola == colb) continue;

		if (s == "move")
		{
			if (ss == "onto")
			{
				for (i = posa + 1; i < depth[cola]; i++) push(stack[cola][i], stack[cola][i]);
				for (i = posb + 1; i < depth[colb]; i++) push(stack[colb][i], stack[colb][i]);
				depth[colb] = posb + 1;

				push(a, colb);
				depth[cola] = posa;
			}
			else
			{
				for (i = posa + 1; i < depth[cola]; i++) push(stack[cola][i], stack[cola][i]);
				push(a, colb);
				depth[cola] = posa;
			}
		}
		else if (s == "pile")
		{
			if (ss == "onto")
			{
				for (i = posb + 1; i < depth[colb]; i++) push(stack[colb][i], stack[colb][i]);
				depth[colb] = posb + 1;
				for (i = posa; i < depth[cola]; i++) push(stack[cola][i], colb);
				depth[cola] = posa;
			}
			else
			{
				for (i = posa; i < depth[cola]; i++) push(stack[cola][i], colb);
				depth[cola] = posa;
			}
		}

	}

	printstack();

	return 0;
}