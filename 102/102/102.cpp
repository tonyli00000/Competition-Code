// 102.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int b, c, g, i, j, k, moves, bin[4][3], number,colors[3],n;
char value[4];



int main()
{
	value[0] = 'B';
	value[1] = 'G';
	value[2] = 'C';
	
	while (cin>>bin[1][0])
	{
		for (i = 1; i <= 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if ((i == 1) && (j == 0))
				{

				}
				else cin >> bin[i][j];
			}
		}
		moves = bin[1][0] + bin[2][1] + bin[3][2] - 1;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				for (k = 0; k < 3; k++)
				{
					if ((i ==j) ||(i == k) || (j == k))
					{
					}
					else
					{
						if (moves < bin[1][i] + bin[2][j] + bin[3][k])
						{
							moves = bin[1][i] + bin[2][j] + bin[3][k];
							colors[0] = i;
							colors[1] = j;
							colors[2] = k;
							n = 100 * value[i] + 10 * value[j] + value[k];
						}
						if (moves == bin[1][i] + bin[2][j] + bin[3][k])
						{
							if (n > 100 * value[i] + 10 * value[j] + value[k])
							{
								n = 100 * value[i] + 10 * value[j] + value[k];
								colors[0] = i;
								colors[1] = j;
								colors[2] = k;
								moves = bin[1][i] + bin[2][j] + bin[3][k];
							}

						}

					}
				}
			}
		}
			i = 1;
			number = 0;
			while (i <= 9)
			{
				for (k = 1; k < 4; k++)
				{
					for (j = 0; j < 3; j++)
					{
						number = number + bin[k][j];
						i++;
					}
				}
			}
			for (k = 0; k < 3; k++)
			{
					if (colors[k] == 0)cout << "B";
					if (colors[k] == 1)cout << "G";
					if (colors[k] == 2)cout << "C";
				
			}
		cout <<" "<< number - moves<<"\n";
	}

	return 0;
}

