#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

long long n;

int main()
{
	int t, tc=1;
	int p;

	cin >> t;
	while(t--){
		cin >> n;
		p = 0;
		while (n > 0) {
			n /= 2;
			p++;
		}
		cout << "Case " << tc++ << ": " << p << "\n";
	}

	return 0;
}