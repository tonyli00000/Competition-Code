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

vector<int> score;
int main()
{
	int i;
	for (i = 0; i <= 20; i++)score.push_back(i);
	for (i = 2; i <= 40; i = i + 2)score.push_back(i);
	for (i = 3; i <= 60; i = i + 3)score.push_back(i);
	sort(score.begin(), score.end());
	int x;
	while (cin >> x && x>=1) {
		int j, k;
		map<set<int>, bool> c;

		int p=0,q=0;
		for (i = 0; i < score.size(); i++) {
			for (j = 0; score[i] + score[j] <= x && score[i]<x  && j < score.size(); j++) {
				for (k = 0; score[i]+score[j]<x && score[i]+score[j]+score[k]<=x && k < score.size(); k++) {
					if (score[i] + score[j] + score[k]==x) {
						p++;
						set<int> a;
						a.insert(i);
						a.insert(j);
						a.insert(k);
						if (c.find(a) == c.end())q++;
					}
				}
			}
		}
		cout << p << " " << q << "\n";
	}
	return 0;
}
