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

int main() {
	long n, i, j, num, sum, d,t,k;
	cin >> t;
	for (k = 0; k < t;k++){
		cin >> n;
		num = n;
		for (j = 1;; j++)
		{
			sum = 0;
			for (i = 1; i != 0; i++)
			{
				d = num % 10;
				num = num / 10;
				sum = sum + d*d;
				if (num == 0)
				{
					num = sum;
					break;
				}
			}
			if (num <= 9)
				break;
		}
		cout << "Case #" << k+1 << ": ";
		if (num == 1 || num == 7)cout << n << " is a Happy number.\n";
		else cout << n << " is an Unhappy number.\n";
	}
	return 0;
}