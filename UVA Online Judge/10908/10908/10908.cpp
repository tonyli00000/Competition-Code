#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int y, q, t, m, n, i, j, k, c, z, g, o, b;
string s, x[22][22], p[22];
int main()
{
	while (cin >> t)
	{
		for (g = 0; g < t; g++){
			cin >> m;
			cin >> n;
			cin >> q;
			
			
				for (j = 0; j < n; j++)
				{
					getline(cin, p[j]);
				}
				for (i = 0; i < n; i++)
				{
					o = p[i].length();

				}
				getline(cin, s);
			for (i = 0; i < q; i++)
			{
				cin >> y;
				cin >> c;
				s = x[y-1][c-1];
				b = 0;
				k = 1;
				while (k == 1){
					b = b + 1;
					for (i = y-1 - b; i <= y -1+b; i++)
					{
						for (j = c - b-1; j <= c + b-1; j++)
						{
							if (x[i][j] != s)k = 0;
						}
					}
					
				}
				cout << 2*b+1;
				
			
			}
			cout << m << " " << n << " " << q;
		}
	}
	return 0;

}

