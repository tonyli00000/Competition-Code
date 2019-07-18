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

char s[] = "AJAJAJAJAJASASASASASABABABABABAKAKAKAKAKATUTUTUTUTUCUCUCUCUCULULULULULUDUDUDUDUDUMUMEMEMEMEVEVEVEVEVENENENENENEWEWEWEWEWEFEFEFOFOFOXOXOXOXOXOGOGOGOGOGOPOPOPOPOPOYOYOYOYIYIHIHIHIHIHIQIQIQIQIQIZIZIZIZIZIRIRIRIRIR";
bool cmp(char a, char b)
{
	return a<b;
}
int main(){
	int t;
	cin >> t;
	int i, j, k;
	for (k = 0; k < t; k++) {
		int n;
		string tmp;
		cin >> n;
		for (i = 0; i < n; i++) {
			tmp+= s[i];
		}
		cout << "Case " << k + 1 <<": "<< tmp << "\n";
	}
	return 0;
}
