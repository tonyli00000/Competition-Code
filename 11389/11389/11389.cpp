#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int i, j, k, x[101], n, d, r, y[101],sums[101],b;
int main()
{
	while ((cin >> n)&&(n!=0)){
		cin >> d;
			cin >> r;
				for (i = 0; i < 101; i++)
				{
					x[i] = 0;
					y[i] = 0;
					sums[101]=0;
				}


				for (i = 0; i < n; i++)	cin >> x[i];
				
				for (i = 0; i < n; i++)cin >> y[i];
				for (i = 0; i < n; i++)
				{
					for (j = i + 1; j < n; j++)
					{
						if (x[j] < x[i])
						{
							k = x[i];
							x[i] = x[j];
							x[j] = k;
						}
					}
				}

				for (i = 0; i < n; i++)
				{
					for (j = i + 1; j < n; j++)
					{
						if (y[j] < y[i])
						{
							k = y[i];
							y[i] = y[j];
							y[j] = k;
						}
					}
				}
				b = n-1;
				for (i = 0; i < n; i++)
				{
						sums[i] = x[i] + y[b];
						b = b - 1;
					
				}
				k = 0;
				for (i = 0; i < n; i++)
				{
					if (sums[i]>d)
					{
						k = k + sums[i] - d;
					}
				}
				cout << k*r << "\n";

	}
	return 0;
}
