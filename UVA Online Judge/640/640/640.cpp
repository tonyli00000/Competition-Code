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
bool self[1500001];

int main(){
	for (int i = 1; i <= 1000000; i++){
		int total = i;
		int temp = i;
		while (temp > 0){
			total += temp % 10;
			temp /= 10;
		}
		self[total] = true;
	}

	for (int i = 1; i <= 1000000; i++){
		if (self[i] == false){
			cout << i << "\n";
		}
	}
	return 0;
}