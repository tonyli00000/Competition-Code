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
bool is_digits_repeated(long long n)
{
	unsigned int digits = 0; 
	do {
		int d = 1 << static_cast<int>(n % 10);
		if (digits & d)
			return true;
		n /= 10;
		digits |= d;
	} while (n);
	return false;
}

int main()
{
	long long s1_max = 9876543210;
	int t;
	cin >> t;
	while (t--) {
		long long N;
		cin >> N;
		for (long long s2 = 1, s2_max = s1_max / N; s2 <= s2_max; s2++)
			if (!is_digits_repeated(s2)) {
				long long s1 = s2 * N;
				if (!is_digits_repeated(s1))
					cout << s1 << " / " << s2 << " = " << N << endl;
			}
		if (t)
			cout << endl;
	}
	return 0;
}