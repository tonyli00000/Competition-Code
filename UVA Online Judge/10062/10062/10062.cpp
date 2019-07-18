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

	int getMax(int array[]);

	int main() {
		string str;
		int freq[150];
		int i, j;
		int size;
		int c;
		int max;
		int flag = 0;

		while (getline(cin,str)) {
			size = str.length();
			for (i = 32; i <= 127; i++) {
				c = 0;
				for (j = 0; j < size; j++) {
					if (i == str[j])c++;
				}
				freq[i] = c;
			}
			max = getMax(freq);

			if (flag)cout << "\n";
			flag = 1;
			for (i = 1; i <= max; i++) {
				for (j = 127; j >= 32; --j) {
					if (i == freq[j])
						cout << j << " " << freq[j] << "\n";
				}
			}
		}

		return 0;
	}
	int getMax(int array[]) {
		int max = 0;
		int i;
		for (i = 32; i <= 127; i++) {
			if (max < array[i])
				max = array[i];
		}
		return max;
	}