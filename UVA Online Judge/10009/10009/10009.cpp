#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;

bool connected[30][30];
int m, n, t,i,j,k,pos,Q[30],dist[26],way[26],previous[26],vertex[30];
string temp;
bool w;
void a(int x, int y, int b){
	int i;
	if(w==true)cout << char(vertex[x] + 'A');
	if ((x == y)&&(w==true)){
		cout << "\n";
		w = false;
		return;
	}
	for (i = 0; i <= b; i++){
		if (previous[i] == x){
			x = i;
			a(x, y, b);
		}
	}
}


void print_route(int y){
	if (previous[y] != -1) print_route(previous[y]);
	cout << vertex[y] + 'A';	
}



int path(int x, int y, int b){
	int i,j,k,v=0,u=0;
	previous[x] = -1;
	for (i = 0; i <= b; i++){
		if (i != x)dist[i] = 60000;
		else dist[x] = 0;
	}
	dist[x] = 0;
	for (i = 0; i <= b; i++){
		int min = 10000,c=0;
		for (j = 0; j <= b; j++){
			if (((dist[j] < min)&&(Q[j]!=0))||((dist[j]<min)&&(i=0))){
				v = j;
				min = dist[j];
			}
		}
		for (j = 0; j <= b; j++){
			if (connected[Q[v]][Q[j]] == true){
				if (dist[j] > dist[v] + 1){
					dist[j] = dist[v] + 1;
					previous[j] = v;
				}
			}
		}
		Q[v] = 0;
		for (j = 0; j <= b; j++)if (Q[j] > 0)break;
		if (j == b + 1)return dist[y];
	}
	return dist[y];
}

int main()
{
	int b=0;
	cin >> t;
	for (k = 0; k < t; k++){
		b = 0;
		for (i = 0; i < 30; i++){
			for (j = 0; j < 30; j++){
				connected[i][j] = false;
			}
		}
		cin >> m >> n;
		getline(cin, temp);
		for (i = 0; i < m; i++){
			getline(cin, temp);
			pos = 0;
			for (j = 0; j < temp.length(); j++){
				if (temp[j] == ' '){
					pos = j;
					break;
				}
			}
			connected[temp[0]-'A'][temp[pos + 1]-'A'] = true;
			connected[temp[pos + 1]-'A'][temp[0]-'A'] = true;
			for (j = 0; j <= b; j++){
				if (temp[0] - 'A' == Q[j])break;
			}
			if (j == b + 1){
				Q[b] = temp[0] - 'A';
				vertex[b] = temp[0] - 'A';
				b++;
			}
			for (j = 0; j <= b; j++){
				if (temp[pos+1] - 'A' == Q[j])break;
			}
			if (j == b + 1){
				Q[b] = temp[pos+1] - 'A';
				vertex[b] = temp[pos + 1] - 'A';
				b++;
			}
		}
		int o = 0, p = 0;
		for (i = 0; i < n; i++){
			getline(cin, temp);
			for (j = 0; j < temp.length(); j++){
				if (temp[j] == ' '){
					pos = j;
					break;
				}
			}
			o = temp[0] - 'A';
			for (j = 0; j <= b; j++){
				if (Q[j] == o){
					o = j;
					break;
				}
			}
			p = temp[pos + 1] - 'A';
			for (j = 0; j <= b; j++){
				if (Q[j] == p){
					p = j;
					break;
				}
			}
			int r = 0,m=0;
			r=path(o, p, b - 1);
			w = true;
			a(o, p,b-1);	
		}
	}
	return 0;

}