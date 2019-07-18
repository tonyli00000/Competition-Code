// 10487.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int x[1001], i, y, number, sum, j, k, z, a, p, closest,difference,d,caseid;


int main()
{
	caseid = 0;
	while (cin >> y,y!=0)
	{
		caseid++;
		cout << "Case "<<caseid<<":\n";
			for (i = 0; i < y; i++)
			{
				cin >> x[i];
			}
			cin >> p;
			for (k = 1; k <= p; k++)
			{
				cin >> z;
				closest = 0;

				difference = abs(z - x[0] - x[1]);
				closest = x[0] + x[1];
				for (i = 0; i < y; i++)
				{
					for (j = i + 1; j < y; j++)
					{

						if (abs(z - x[i] - x[j]) < difference)
						{
							difference = abs(z - x[i] - x[j]);
							closest = x[i] + x[j];
						}
					}
				}
				cout << "Closest sum to " << z << " is " << closest << ".\n";
			
				
			}
	
	}
	return 0;
}

