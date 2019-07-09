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
#include <algorithm>

using namespace std;

int main()
{
	int tc, t = 1;

	double u, v, dist, t1, t2, td;

	cin >> tc;
	while (tc--)
	{
		cin >> dist >> v >> u;
		cout << "Case " << t++ << ": ";
		if (v == 0 || u == 0 || v >= u)
		{
			cout << "can't determine\n";
			continue;
		}
		t1 = (1.0*dist) / (u*1.0);
		t2 = (1.0*dist) / (sqrt((u*u) - (v*v))*1.0);

		td = abs(t2 - t1);

		cout << fixed << setprecision(3) << td << "\n";
	}

	return 0;
}