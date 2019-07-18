#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>

using namespace std;



int main()
{
	int i, t, j, k;
	cin >> t;
	for (k = 0; k < t; k++) {
		int n;
		cin >> n;
		int arr[2005], forw[2005], back[2005];
		for (i = 0; i < n; i++) {
			cin >> arr[i];
			forw[i] = 1;
			back[i] = 1;
		}
		int lo, hi, L = 0;
		int maxi = 0;
		for (i = n - 1; i >= 0; i--)
		{
			for (j = i + 1; j<n; j++)
			{
				if (arr[i]<arr[j])
					forw[i] = max(forw[i], forw[j] + 1);
				if (arr[i]>arr[j])
					back[i] = max(back[i], back[j] + 1);
			}
			maxi = max(forw[i] + back[i] - 1, maxi);
		}

		cout << maxi << "\n";
	}

    return 0;
}

