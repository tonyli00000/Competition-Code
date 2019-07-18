#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#define MAXN 10000
using namespace std;
int i, j, k,energy[30][30],vertex1[30],dist[30][30],prec[30][30],matrix1[30][30],matrix2[30][30];
int vertex2[30];
bool age[30][30];

void find(int last){
	int i, j, k;
	for (i = 0; i < 30; i++)
		for (j = 0; j < 30; j++)dist[i][j] = MAXN;
	for (i = 0; i < last; i++)dist[vertex1[i]][vertex1[i]] = 0;
	for (i = 0; i < last; i++){
		for (j = 0; j < last; j++){
			if (matrix1[vertex1[i]][vertex1[j]]>0){
				dist[vertex1[i]][vertex1[j]] = matrix1[vertex1[i]][vertex1[j]];
			}
			if (matrix2[vertex1[i]][vertex1[j]]>0){
				dist[vertex1[i]][vertex1[j]] = matrix2[vertex1[i]][vertex1[j]];
			}
		}
	}
	for (k = 0; k < last; k++){
		for (i = 0; i < last; i++){
			for (j = 0; j < last; j++){
				if ((dist[vertex1[i]][vertex1[j]] > dist[vertex1[i]][vertex1[k]] + dist[vertex1[k]][vertex1[j]]) && (((matrix1[vertex1[i]][vertex1[k]]>0) && (matrix1[vertex1[k]][vertex1[j]]>0)) || ((matrix2[vertex1[i]][vertex1[k]]>0) && (matrix2[vertex1[k]][vertex1[j]]>0)))){
					dist[vertex1[i]][vertex1[j]] = dist[vertex1[i]][vertex1[k]] + dist[vertex1[k]][vertex1[j]];
				}

			}
		}
	}
}

int main()
{
	int t,e,last,last2;
	char a, b, c, d;
	while (cin >> t && t != 0){
		for (i = 0; i < 30; i++){
			for (j = 0; j < 30; j++){
				matrix1[i][j] = -1;
				matrix2[i][j] = -1;
			}
		}
		for (i = 0; i < 30; i++){
			vertex1[i] = -1;
			vertex2[i] = -1;
		}
		last = 0;
		last2 = 0;
		for (i = 0; i < t; i++){
			cin >> a >> b >> c >> d>>e;
			if (a == 'Y'){
				if (b == 'U')matrix1[c - 'A'][d - 'A'] = e;
				else{
					matrix1[c - 'A'][d - 'A'] = e;
					matrix1[d - 'A'][c - 'A'] = e;
				}
			}
			else{
				if (b == 'U')matrix2[c - 'A'][d - 'A'] = e;
				else{
					matrix2[c - 'A'][d - 'A'] = e;
					matrix2[d - 'A'][c - 'A'] = e;
				}
			}
			for (j = 0; j < last; j++)if (vertex1[j] == c - 'A')break;
			if (j == last){
				vertex1[last] = c - 'A';
				last++;
			}
			for (j = 0; j < last; j++)if (vertex1[j] == d - 'A')break;
			if (j == last){
				vertex1[last] = d - 'A';
				last++;
			}
		}
		find(last);
		cin >> c >> d;
		int k = 30000,v=0;
		if (c == d)cout << 0 << " " << char(d) << "\n";
		else {
			for (i = 0; i < last; i++){
				if (vertex1[i] != c - 'A' && vertex1[i] != d - 'A'){
					if (matrix1[c - 'A'][vertex1[i]] != -1 && matrix2[d - 'A'][vertex1[i]] != -1){
						if (dist[c - 'A'][vertex1[i]] + dist[d - 'A'][vertex1[i]] < k){
							k = dist[c - 'A'][vertex1[i]] + dist[d - 'A'][vertex1[i]];
							v = i;
						}
					}
				}
			}
			char l = char(vertex1[v] + 'A');
			if (matrix1[c - 'A'][d - 'A'] < k && matrix1[c - 'A'][d - 'A'] != -1){
				k = matrix1[c - 'A'][d - 'A'];
				char l = d;
			}
			if (matrix2[d - 'A'][c - 'A'] < k && matrix2[d - 'A'][c - 'A'] != -1){
				k = matrix2[d - 'A'][c - 'A'];
				char l = c;
			}
			
			if(k<30000)cout << k << " " << l << "\n";
			else cout << "You will never meet.\n";
		}
	}
	return 0;
}

