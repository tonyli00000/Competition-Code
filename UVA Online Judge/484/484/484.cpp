#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int i, j, k;
	string line;
		map <int, int> num;
		queue <int> order;
		int sum;
		while(cin>>sum){
			if (num.find(sum) != num.end())num[sum]++;
			else {
				num.emplace(sum, 1);
				order.push(sum);
			}
		}
	
		while (!order.empty()) {
			cout << order.front() << ' ' << num[order.front()] << '\n';
			order.pop();
		}
	
	return 0;
}
