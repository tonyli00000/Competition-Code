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

#define MAXSIZE 45
#define MAXCOLOR 1650
using namespace std;


int canvas[MAXSIZE][MAXSIZE],i,j,k;
int maxx[MAXCOLOR], maxy[MAXCOLOR],minx[MAXCOLOR],miny[MAXCOLOR];
map<int, int>color;
vector<vector<int>>overlap;
bool drawn[MAXCOLOR];
int main()
{
	int n;
	cin >> n;
	for (i = 0; i < MAXCOLOR; i++){
		maxx[i] = -1;
		maxy[i] = -1;
		minx[i] = -1;
		miny[i] = -1;
		drawn[i] = false;
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			cin >> canvas[i][j];
			if (canvas[i][j] != 0){
				maxx[canvas[i][j]] = max(maxx[canvas[i][j]], i);

				if(minx[canvas[i][j]]!=-1)minx[canvas[i][j]] = min(minx[canvas[i][j]], i);
				else minx[canvas[i][j]] = i;

				maxy[canvas[i][j]] = max(maxy[canvas[i][j]], j);

				if (miny[canvas[i][j]] != -1)miny[canvas[i][j]] = min(miny[canvas[i][j]], j);
				else miny[canvas[i][j]] =j;

				color[canvas[i][j]] = 1;
			}
		}
	}
	overlap.resize(MAXCOLOR);
	for (auto it = color.begin(); it != color.end(); it++){
		for (i = minx[it->first]; i <= maxx[it->first]; i++){
			for (j = miny[it->first]; j <= maxy[it->first]; j++){
				if (canvas[i][j] != it->first){
					overlap[it->first].push_back(canvas[i][j]);
				}
			}
		}
	}
	int ct = 0,rounds=0;
	vector<int>removed;
	
	while (true){
		bool finished = true;
		for (auto it = color.begin(); it != color.end(); it++){
			if (!drawn[it->first]){
				finished = false;
				break;
			}
		}
		if (finished)break;
		for (auto it = color.begin(); it != color.end(); it++){
			for (i = 0; i < overlap[it->first].size(); i++){
				if (!drawn[overlap[it->first][i]])break;
			}
			if (i==overlap[it->first].size()){
				removed.push_back(it->first);
			}
		}
		for (i = 0; i < removed.size(); i++){
			drawn[removed[i]] = true;
		}
		removed.clear();
		rounds++;
	}
	cout << rounds << "\n";
	return 0;
}
