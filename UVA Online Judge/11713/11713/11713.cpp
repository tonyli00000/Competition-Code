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
	int i, j, t, l1, l2, d;
	string s1, s2;
	cin >> t;
	for (i = 0; i < t;i++)
	{
		for (i = 0; i<t; i++)
		{
			cin >> s1;
			cin >> s2;
			l1 = s1.length();
			l2 = s2.length();
			if (l1 != l2)
			{
				cout<<"No\n";   continue;
			}
			else
				for (j = 0; j<l1; j++)
				{
					if (s1[j] != s2[j])
					{
						if (s1[j] == 'a' || s1[j] == 'e' || s1[j] == 'i' || s1[j] == 'o' || s1[j] == 'u')
						{
							if (s2[j] == 'a' || s2[j] == 'e' || s2[j] == 'i' || s2[j] == 'o' || s2[j] == 'u') d = 1;
							else
							{
								cout<<"No\n";
								break;
							}
						}
						else
						{
							cout<<"No\n";
							break;
						}
					}
					if (j == l1 - 1)
					{
						cout<<"Yes\n";
						break;
					}
				}

		}
	}
}