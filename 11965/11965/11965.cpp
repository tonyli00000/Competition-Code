#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int i, j, k, a, b, c, x, n;
string y;

int main()
{
	cin >> n;
	for (k = 0; k < n; k++)
	{
		
		cin >> b;
		cout << "Case " << k + 1 << ":\n";
		for (j = 0; j < b; j++)
		{ 
			if (j == 0){
				getline(cin, y);
				getline(cin, y);
			}
			else getline(cin, y);
			c = y.length();
			/*if (y[0] == '	')
			{
				for (i = 0; i < c; i++)
				{
					if (y[i] != '	')
					{
						x = i;
						break;
					}
				}
				y.erase(0, x);
				y.insert(0, " ");
			}
			if (y[0] == ' ')
			{
				for (i = 0; i < c; i++)
				{
					if (y[i] != ' ')
					{
						x = i;
						break;
					}
				}
				y.erase(0, x);
				y.insert(0, " ");
			}*/
			
				for (i = 0; i < c-1; i++)
				{
					if ((y[i] == ' ') && (y[i + 1] == ' '))
					{
						y.erase(i + 1, 1);
						i = i-1;
						c = y.length();
					}
				}
			
			cout << y << "\n";
			
		}
		if (k < n - 1)cout << "\n";

	}
	return 0;
}


