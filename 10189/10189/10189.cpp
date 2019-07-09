// 10189.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int x[101][101], i, j, k,n,m;


int main()
{
	while (cin >> n >> m, n != 0)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				cin >> x[i][j];
			}
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (x[i][j] == "*")
				{
					
				}
			}
		}

	}
	return 0;
}

