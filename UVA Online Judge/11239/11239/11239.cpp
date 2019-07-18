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

bool myfunction(pair<string,long>i, pair<string,long>j) { return (i.second>j.second); }
int main()
{
	while (true){
		string proj;

		getline(cin, proj);
		if (proj == "0")break;
		int ct = 0;
		map<string, long>project;
		map<string, set<string>>pro;
			string uid;
			bool end = false;
			project[proj] = 0;
			while (getline(cin,uid)){
				if (uid == "1"){
					end = true;
					break;
				}
				if ('A' <= uid[0] && uid[0] <= 'Z'){
					proj = uid;
					ct++;
					project[proj] = 0;
					continue;
				}
				pro[uid].insert(proj);
			}
			if (end){
				
				for (auto it = pro.begin(); it != pro.end(); it++){
					if (it->second.size() > 1)continue;
					for (auto jt = it->second.begin(); jt != it->second.end(); jt++){
						project[*jt]++;
					}
				}
				vector < pair<string, long> > ans;
				for (auto it = project.crbegin(); it != project.crend(); it++){
					ans.push_back(make_pair(it->first, it->second));
					
				}
				sort(ans.begin(), ans.end(), myfunction);
				for (int i = 0; i < ans.size(); i++){
					cout << ans[i].first << " " << ans[i].second << "\n";
				}
			}
		}

	
	return 0;
}
