#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
string x[100];
char s;
int y, i, j, k, m, n, c, r, t, q, o, u, b, g;
int main()
{
	cin >> t;
	for (i = 0; i < t; i++)
	{
		cin >> m;
		cin >> n;
		cin >> q;
		cout << m << " " << n << " " << q << "\n";
		for (j = 0; j < m; j++)
		{
			cin >> x[j];
		}
		for (g = 0; g < q; g++)
		{
			cin >> c;
			cin >> r;
			b = 0;
			u = 0;
			s = x[c][r];
			while ((c - b >= 0) && (r - b >= 0) && (r+b<n)&&(c+b<m)&&(u != 1))
			{
				for (j = c - b ; j <= c + b; j++)
				{
					for (k = r - b ; k <= r + b; k++)
					{
						if (x[j][k] != s)
							u = 1;
					}
				}
				b = b + 1;
			}
			if (u == 1) b--;
			cout << 2 * (b - 1) + 1<<"\n";
		}
	}
	return 0;
}
