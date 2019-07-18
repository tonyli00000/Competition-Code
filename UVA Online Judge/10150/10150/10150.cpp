#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory.h>
#include <queue>

using namespace std;

vector<string> dict;
map<string, int> pos;
vector<int>nex(25200);
int main()
{
	string line;
	while (getline(cin, line), line != ""){
		pos[line] = dict.size();
		dict.push_back(line);
	}

	int f = 0;
	string s, t;
	while (cin >> s >> t){
		if (f++) cout<<"\n";
		if (pos.find(s) == pos.end()){
			cout<<"No solution.\n";
			continue;
		}
		if (pos.find(t) == pos.end()){
			cout << "No solution.\n";
			continue;
		}
		nex.assign(-1, 25200);
		int ids = pos[s];
		int idt = pos[t];
		nex[idt] = -2;
		queue< int > q;
		q.push(idt);
		while (!q.empty()){
			int u = q.front(); q.pop();
			string s = dict[u];
			for (int i = 0; i<s.length(); i++)
				for (int c = 'a'; c <= 'z'; c++){
					string t = s;
					t[i] = c;
					if (pos.find(t) != pos.end()){
						int v = pos[t];
						if (nex[v] == -1){
							nex[v] = u;
							q.push(v);
						}
					}
				}
		}
		if (nex[ids] == -1) cout << "No solution.\n";
		else for (int i = ids; i != -2; i = nex[i]) cout << dict[i] << "\n";
	}

	return 0;
}