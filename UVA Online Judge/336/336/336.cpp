#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int i, j, k,u,v;
bool connected[33][33];
bool node[33],temp[33];
int nodes[33];

void search(int m, int n, int ttl){
	int i, j, k=ttl;
	u = m;
	node[u] = true;
	temp[u] = true;
	while (ttl > 0){
		for (j = 0; j < 33; j++){
			if (temp[j] == true){
				u = j;
				for (i = 0; i < 33; i++){
					if (connected[u][i] == true){
						node[i] = true;
						temp[i] = true;
					}
				}
				temp[j] = false;
			}
			
		}
		ttl--;
	}
}
int main()
{
	int m, n, t,nodenum=0;
	while (cin >> t){
		for (i = 0; i < 33; i++){
			for (j = 0; j < 33; j++){
				connected[i][j] = false;
			}
		}
		for (i = 0; i < t; i++){
			cin >> m >> n;
			int p = 0;
			for (j = 0; j < 33; j++){
				if (nodes[j] == m){
					p = 1;
					break;
				}
			}
			if (p == 0){
				nodes[nodenum] = m;
				m = nodenum;
				nodenum++;
			}
			p = 0;
			for (j = 0; j < 33; j++){
				if (nodes[i] == n){
					p = 1;
					break;
				}
			}
			if (p == 0){
				nodes[nodenum] = n;
				n = nodenum;
				nodenum++;
			}
			connected[m][n] = true;
			connected[n][m] = true;
		}
		while ((cin >> m >> n) && (m != 0) && (n != 0)){
			int ttl = n;
			for (i = 0; i < 33; i++){
				node[i] = false;
				temp[i] = false;
			}
			for (i = 0; i < 33; i++){
				if (nodes[i] = m){
					m = i;
					break;
				}
			}
			int l = 0;
			search(m, n, ttl);
			int q=0;
			for (i = 0; i < nodenum-1; i++){
				if (node[i] == false)q++;
			}
			cout << q << "\n";
		}
	}
	return 0;

}