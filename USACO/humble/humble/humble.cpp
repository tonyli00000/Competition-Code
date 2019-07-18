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

int pn, p[101], n;
set<int> si;

int main()
{

	cin >> pn >> n;
	for (int i = 0; i != pn; i++)
	{
		cin >> p[i];
		si.insert(p[i]);
	}
	for (int i = 0; i != pn; i++)
	{
		auto it = si.begin();
		while (1)
		{
			int t = (*it)*p[i];
			if (t<0) break;
			if (si.size()>n)
			{
				si.erase(--si.end());
				if (t>(*(--si.end()))) break;
			}
			si.insert(t);
			it++;
		}
	}
	cout << *(--si.end()) << endl;
	return 0;
}

