#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int n,i,j,k;
	while (cin >> n) {
		bool p[3010];
		for (i = 0; i < n; i++)p[i] = false;
		vector <int> arr;
		arr.resize(n);
		for (i = 0; i < n; i++)
			cin >> arr[i];
		for (i = 0; i < n - 1;i++) {
			p[abs(arr[i] - arr[i + 1])] = true;
			if (abs(arr[i] - arr[i + 1])==0)break;
			if (abs(arr[i] - arr[i + 1])>n - 1)break;
		}
		if (i != n - 1)cout << "Not jolly\n";
		else {
			for (i = 1; i < n; i++) {
				if (!p[i])break;
			}
			if (i == n)cout << "Jolly\n";
			else cout << "Not jolly\n";
		}
	}
	return 0;
}
