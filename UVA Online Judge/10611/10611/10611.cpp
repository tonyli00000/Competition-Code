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
	long n, m,i,j,k;
	vector<unsigned long long>height;
	cin >> n;
	for (i = 0; i < n; i++){
		long long x;
		cin >> x;
		height.push_back(x);
	}
	sort(height.begin(), height.end());
	cin >> m;
	while (m--){
		long long x;
		cin >> x;
		if (n == 1 && x == height[0])
			printf("X X\n");
		else if (x<height[0])
			printf("X %d\n", height[0]);
		else if (x == height[0])
			printf("X %d\n", height[1]);
		else if (x>height[n - 1])
			printf("%d X\n", height[n - 1]);
		else if (x == height[n - 1])
			printf("X %d\n", height[n - 2]);
		continue;
		for (i = 0; i < height.size() - 1; i++){
			if (x>=height[i] && x <= height[i + 1]){
				long a = i, b = i + 1;
				if (x == height[i]){
					if (i>1)a--;
					else continue;
				}
				if (x == height[i+1]){
					if (i<height.size()-1)b++;
					else continue;
				}
				cout << height[a] << " " << height[b] << "\n";
				break;
			}
		}
	}
	return 0;
}
