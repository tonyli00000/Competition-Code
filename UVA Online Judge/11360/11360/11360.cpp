#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int t;
	cin >> t;
	int i, j, k;
	int arr[11][11],copy[11][11];
	for (k = 0; k < t; k++) {
		if (k != 0)cout << "\n";
		cout << "Case #"<<k+1<<"\n";
		int n;
		cin >> n;
		char c;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				cin >> c;
				arr[i][j] = c - '0';
			}
		}
		string line;
		int p;
	
		cin >> p;
		for (i = 0; i < p; i++) {
			cin >> line;
			if (line == "row") {
				int a, b;
				cin >> a >> b;
				for (j = 0; j < n; j++) {
					int temp=arr[a-1][j];
					arr[a - 1][j] = arr[b - 1][j];
					arr[b - 1][j] = temp;
				}
			}
			else {
				if (line == "col") {
					int a, b;
					cin >> a >> b;
					for (j = 0; j < n; j++) {
						int temp = arr[j][a-1];
						arr[j][a-1] = arr[j][b-1];
						arr[j][b-1] = temp;
					}
				}
				else {
					if (line == "dec" || line == "inc") {
						int o;
						if (line == "dec")o = -1;
						if (line == "inc")o = 1;
						int l;
						for (j = 0; j < n; j++) {
							for (l = 0; l < n; l++) {
								arr[j][l] += o;
								if (arr[j][l] == 10)arr[j][l] = 0;
								if (arr[j][l] == -1)arr[j][l] = 9;
							}
						}
					}
					else {
						int l,a[11][11];
						for (j = 0; j < n; j++) {
							for (l = 0; l < n; l++) {
								a[j][l] = arr[l][j];
							}
						}
						for (j = 0; j < n; j++) {
							for (l = 0; l < n; l++) {
								arr[j][l] = a[j][l];
							}
						}
					}
				}
			}
		}
		int l;
		for (j = 0; j < n; j++) {
			for (l = 0; l < n; l++) {
				cout << arr[j][l];
			}
			cout << "\n";
		}
	}
	return 0;
}
