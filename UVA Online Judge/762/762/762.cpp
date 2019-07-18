#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#define MAXN 900

using namespace std;
int i, j, k, t, dist[MAXN], previous[MAXN],a,c,Q[MAXN],ways[MAXN];
string ss, sa, sb, nodes[MAXN];
bool connected[MAXN][MAXN];

void print_path(int y){
	if (previous[y] != -1) {
		print_path(previous[y]);
			cout << nodes[previous[y]] << " " << nodes[y]<<"\n";
	}	
}
int path(int x, int y, int b){
	int i, j, k, v = 0, u = 0,r=0,prevv=0;
	previous[x] = -1;
	for (i = 0; i < b; i++){
		if (i != x)dist[i] = 30000;
		else dist[x] = 0;
		previous[i] = -1;
		Q[i] = 1;
	}
	dist[x] = 0;
	for (i = 0; i < b; i++){
		int min = 35001;
		for (j = 0; j < b; j++){
			if ((dist[j] < min) && (Q[j] != -1)){
				v = j;
				min = dist[j];
			}
		}
		for (j = 0; j < b; j++){
			if (connected[v][j]){
				if (dist[j] > min + 1){
					dist[j] = min + 1;
					previous[j] = v;
				}
			}
		}
		Q[v] = -1;
		/*for (j = 0; j < b; j++)if (Q[j] > 0)break;
		if ((j == b)||((prevv==v)&&(r>0)))return dist[y];
		prevv = v;
		r++;*/
	}
	return dist[y];
}

int main()
{
	int testcount = 0;

	while (cin >> t){
		testcount++;
		if (testcount > 1) cout << "\n";
		for (i = 0; i < MAXN; i++){
			for (j = 0; j < MAXN; j++){
				connected[i][j] = false;
			}
		}
		for (j = 0; j < MAXN; j++){
			nodes[j] = "";
			Q[j] = -1;
			previous[j] = -1;
		}

		int b = 0;
		getline(cin, ss);
		for (i = 0; i < t; i++){
			getline(cin, ss);
			stringstream sss(ss);
			sss << ss;
			sss >> sa >> sb;
			for (j = 0; j < b; j++){
				if (nodes[j] == sa)break;
			}
			if (j == b){
				nodes[b] = sa;
				b++;
			}
			for (j = 0; j < b; j++){
				if (nodes[j] == sb)break;
			}
			if (j == b){
				nodes[b] = sb;
				b++;
			}
			for (j = 0; j < b; j++){
				if (nodes[j] == sa)a = j;
				if (nodes[j] == sb)c = j;
			}
			connected[a][c] = true;
			connected[c][a] = true;
		}
		getline(cin, ss);
		stringstream sss(ss);
		sss << ss;
		sss >> sa >> sb;
		for (j = 0; j < b; j++)Q[j] = j;
		a = -1;
		c = -1;
		for (j = 0; j < b; j++){
			if (nodes[j] == sa)a = j;
			if (nodes[j] == sb)c = j;
		}
		if (a == -1 || c == -1)cout << "No route\n";
		else{
			int r;
			r = path(a, c, b);
			if (r == 30000)cout << "No route\n";
			else {
				if (r == 0)cout << "No route\n";
				else print_path(c);
			}
		}
	}
	return 0;

}
