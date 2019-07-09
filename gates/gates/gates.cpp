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
	int n,i,j,k;
	cin >> n;
	int x = 0, y = 0,xmin=0,ymax=0;
	set<pair<int, int>>points;
	points.insert(make_pair(0, 0));
	for (i = 0; i < n; i++){
		char c;
		cin >> c;
		if (c == 'N')y++;
		if (c == 'S')y--;
		if (c == 'E')x++;
		if (c == 'W')x--;
		
	}
	return 0;
}
