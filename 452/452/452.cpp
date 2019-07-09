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
	string line;
	int dist[100][100], i, j, k;
	int station[100], t,tc=0;
	cin >> t;
	getline(cin, line);
	getline(cin, line);
	while (t--){
		if (tc)cout << "\n";
		tc++;
		while (getline(cin, line)){
			if (!line.length()){
				for (i = 0; i < 26; i++){
					for (j = 0; j < 26; j++){
						if (dist[i][j] == 1){
							dist[i][j] = station[i] + station[j];
						}
					}
				}
				for (k = 0; k < 26; k++){
					for (i = 0; i < 26; i++){
						for (j = 0; j < 26; j++){
							if (dist[i][k] != -1 && dist[k][j] != -1 && dist[i][k] + dist[k][j] - station[k] > dist[i][j])dist[i][j] = dist[i][k] + dist[k][j] - station[k];
						}
					}
				}
				int result = -1;
				for (i = 0; i < 30; i++){
					for (j = 0; j < 30; j++){
						result = max(result, dist[i][j]);
						dist[i][j] = -1;
					}
					station[i] = 0;
				}
				cout << result << "\n";
			}
			else{
				stringstream ss(line);
				char a, b;
				ss >> a >> b;
				station[a - 'A'] = b - '0';
				string x;
				ss >> x;
				for (i = 0; i < x.length(); i++){
					dist[x[i] - 'A'][a - 'A'] = 1;
				}
			}
		}
	}
	for (i = 0; i < 26; i++){
		for (j = 0; j < 26; j++){
			if (dist[i][j] == 1){
				dist[i][j] = station[i] + station[j];
			}
		}
	}
	for (k = 0; k < 26; k++){
		for (i = 0; i < 26; i++){
			for (j = 0; j < 26; j++){
				if (dist[i][k] != -1 && dist[k][j] != -1 && dist[i][k] + dist[k][j] - station[k] > dist[i][j])dist[i][j] = dist[i][k] + dist[k][j] - station[k];
			}
		}
	}
	int result = -1;
	for (i = 0; i < 30; i++){
		for (j = 0; j < 30; j++){
			result = max(result, dist[i][j]);
			dist[i][j] = -1;
		}
		station[i] = 0;
	}
	cout << result << "\n";
	return 0;
}
