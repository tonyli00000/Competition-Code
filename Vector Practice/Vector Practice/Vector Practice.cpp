#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool function(int x, int y) {
	if(x%10==y%10)return (x / 10 < y / 10);
	else return(x % 10 < y % 10);
}
int main()
{
	vector <int> num;
	vector <int> n;
	for (int i = 0; i < 20; i++)n.push_back(rand() % 100);
	for (int i = 0; i < 20; i++)cout << n[i] << " ";
	cout << "\n";
	sort(n.begin(), n.begin() + 20,function);
	for (int i = 0; i < 20; i++)cout << n[i] << " ";
	cout << "\n";
		//vector <int> num;
		//num.resize(10);
		//for (int i = 0; i < 10; i++) {
		//	num[i] = 5;
		//}
		//num.resize(20, 99);
		//for (int i = 0; i < num.size(); i++) {
		//	cout << num[i] << " ";
		//}
		//cout << "\n";

	
	return 0;
}
