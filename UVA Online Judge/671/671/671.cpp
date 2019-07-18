#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

int i, j, k,pr[10000];
string line;
string dict[10000];
int main()
{
	int t;
	int c = 0;
	while (true) {
		int ind = 0,in=0;
		for (i = 0; i < 5000; i++)pr[i] = 0;
		while (getline(cin, line) && line != "#") {
			dict[ind] = line;
			ind++;
		}
		while (getline(cin, line) && line != "#") {
			for (i = 0; i < ind; i++)if (line == dict[i])break;
			if (i != ind)cout << line << " is correct";
			else {
				string temp = "";
				string tmp = "";
				cout << line << ":";
				for (i = 0; i <= line.length(); i++) {
					temp = "";
					tmp = "";
					for (j = 0; j < i; j++) {
						temp = temp + line[j];
					}
					for (j = i; j < line.length(); j++)tmp = tmp + line[j];
					for (j = 0; j < ind; j++) {
						if (abs(dict[j].length() - line.length()>2))break;
						for (k = 0; k < 26; k++) {
							string l;
							l = char(k + 'a');
							l = temp+l;
							if (l + tmp == dict[j]) {
								int o;
								for (o = 0; o < in; o++)if (pr[o] == j)break;
								if (o == in) {
									cout << " "<<dict[j];
									pr[in] = j;
									in++;
								}
							}
						}
					}
				}
				for (i = 0; i <= line.length(); i++) {
					temp = "";
					tmp = "";
					for (j = 0; j < i; j++) {
						temp = temp + line[j];
					}
					for (j = i+1; j < line.length(); j++)tmp = tmp + line[j];
					for (j = 0; j < ind; j++) {
						if (abs(dict[j].length() - line.length()>0))break;
						for (k = 0; k < 26; k++) {
							if (temp + char('a' + k) + tmp == dict[j]) {
								int o;
								for (o = 0; o < in; o++)if (pr[o] == j)break;
								if (o == in) {
									cout << " "<<dict[j];
									pr[in] = j;
									in++;
								}
							}
						}
					}
				}
				string ch = line;
				for (i = 0; i < line.length(); i++) {
					ch = line;
					ch.erase(i, 1);
					for (j = 0; j < ind; j++) {
						if (abs(dict[j].length() - line.length()>1))break;
						if (ch==dict[j]) {
							int o;
							for (o = 0; o < in; o++)if (pr[o] == j)break;
							if (o == in) {
								cout << " "<<dict[j];
								pr[in] = j;
								in++;
							}
						}
					}
				}
			}
			cout << "\n";
		}
	}
	return 0;
}
