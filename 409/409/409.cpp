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
	int m, n,i,j,k,t=0;
	while (cin >> m >> n) {
		string line;
		vector<string>kw;
		vector<string>excuses;
		getline(cin, line);
		for (i = 0; i < m; i++) {
			getline(cin, line);
			kw.push_back(line);
		}
		vector<int>incidents;
		for (i = 0; i < n; i++) {
			getline(cin, line);
			excuses.push_back(line);
			for (k = 0; k < line.length(); k++) {
				if (line[k] >= 'A'&&line[k] <= 'Z')line[k] += ('a' - 'A');
				else {
					if (line[k] == '.' || line[k] == ',' || line[k] == '!' || line[k] == '?')line[k] = ' ';
				}
			}
			stringstream ss(line);
			int ct = 0;
			while (ss >> line) {
				for (j = 0; j < m;j++)
					if (line == kw[j])ct++;
			}

			incidents.push_back(ct);
		}
		int mx = 0;
		vector<int>out;
		for (i = 0; i < incidents.size(); i++) {
			if (incidents[i] > mx) {
				out.clear();
				mx = incidents[i];
				out.push_back(i);
			}
			else if (incidents[i] == mx)out.push_back(i);
		}
		cout << "Excuse Set #" << ++t << "\n";
		for (i = 0; i < out.size(); i++) {
			cout << excuses[out[i]] << "\n";
		}
		cout << "\n";
	}
	return 0;
}
