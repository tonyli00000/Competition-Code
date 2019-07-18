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
int i, j, k;

long long dist[100][100];
map<char, int>name;
int main()
{
	for (i = 0; i < 100; i++){
		for (j = 0; j < 100; j++){
			dist[i][j] = 10000000000;
		}
	}
	int p;
	cin >> p;
	for (i = 0; i < p; i++){
		long long d;
		char c1, c2;
		cin >> c1 >> c2;
		cin >> d;
		if (name.find(c1) == name.end())name[c1] = name.size();
		if (name.find(c2) == name.end())name[c2] = name.size();
		dist[name[c1]][name[c2]] = min(dist[name[c1]][name[c2]], d);
		dist[name[c2]][name[c1]] = min(dist[name[c2]][name[c1]], d);
	}
	for (k = 0; k < name.size(); k++){
		for (i = 0; i < name.size(); i++){
			for (j = 0; j < name.size(); j++){
				if (dist[i][j]>dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	char cow = ' ';
	long long out = 1000000000000000;
	for (auto it = name.begin(); it != name.end(); it++){
		if (it->first == 'Z' || ('a' <= it->first && it->first <= 'z'))continue;
		if (dist[it->second][name['Z']] < out){
			out = dist[it->second][name['Z']];
			cow = it->first;
		}
	}
	cout << cow << " " << out << "\n";
	return 0;
}
