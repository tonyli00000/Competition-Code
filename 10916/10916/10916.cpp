#include<iostream>
#include<cmath>

using namespace std;

int f[21];

int main()
{
	int n, i, j, k;
	double sum = 0;
	for (i = 0, j = 0, k = 4; i<21; i++, k *= 2)
	{
		for (j++; ; j++)
		{
			sum += log10((double)j);
			if (sum >= k*log10(2.))
			{
				f[i] = j - 1;
				break;
			}
		}
	}
	while (cin >> n, n)
		cout << f[(n - 1960) / 10] << endl;
	return 0;
}