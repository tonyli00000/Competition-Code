#include <iostream>
using namespace std;

int main()
{
	int fac[13];
	fac[0] = 1;
	for (int i = 1; i < 13; ++i)
		fac[i] = i * fac[i - 1];

	int n, k;
	while (cin >> n >> k)
	{
		int product = 1;
		for (int i = 1; i <= k; ++i)
		{
			int n_i;
			cin >> n_i;
			product *= fac[n_i];
		}
		cout << fac[n] / product << endl;
	}
	return 0;
}