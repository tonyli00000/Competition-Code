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
int GCD(int a, int b)
{
	int c;
	while (a != 0)
	{
		c = b%a;
		b = a;
		a = c;
	}
	return(b);
}
int main()
{
	int a, b, N;
	//freopen("in.txt","r",stdin);
	while (cin>>N && N)
	{
		long G = 0;
		for (a = 1; a<N; a++)
			for (b = a + 1; b <= N; b++)
			{
				G += GCD(a, b);
			}
		cout << G << "\n";
	}
	return(0);
}