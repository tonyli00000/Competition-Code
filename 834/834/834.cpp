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
	int a, b;
	vector<int>output;
	while (cin >> a >> b) {
		if (a == 1) {
			cout << "[0;" << b << "]\n";
			continue;
		}
		while (a != 1) {
			int c = a / b;
			a -= c*b;
			int temp = a;
			a = b;
			b = temp;
			output.push_back(c);
		}
		cout << "[";
		cout << output[0] << ";";
		cout << output[1];
		for (int i = 2; i < output.size(); i++) {
			cout << "," << output[i];
		}
		cout << "]\n";
	}
    return 0;
}

