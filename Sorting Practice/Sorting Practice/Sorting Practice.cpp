#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int i, j, k;
int main()
{
	int n = 10, a[10] = { 8, 9, 12, 4, 1, 28, 94, 1, 44, 40 };
	for (i = 0; i < 10; i++)
	{
		for (j = i + 1; j < 10; j++)
		{
			if (a[j] < a[i])
			{
				k = a[i];
				a[i] = a[j];
				a[j] = k;
			}
		}
	}
	for (i = 0; i < 10; i++)cout << a[i]<<" ";
	return 0;

}