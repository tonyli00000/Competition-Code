#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#define MAXN 10020
using namespace std;


int main()
{
	int i, j, k,time;
	int n, t,c;
	queue <int> left;
	queue <int>right;
	string direction;
	int side[MAXN];
	queue <int> departure;
	int p,boat[MAXN];
	cin >> p;
	for (k = 0; k < p; k++) {
		if (k > 0)cout << "\n";
		cin >> n >> t >> c;
			int dir = 0;
			int x, ind = 0, time = 0, max = 0;
			for (i = 0; i < c; i++) {
				cin >> x >> direction;
				side[i] = x;
				if (x > max)max = x;
				if (direction == "right")right.push(x);
				else left.push(x);
			}
			dir = 0;
			time = 0;
			bool used[MAXN];
			for (i = 0; i < c; i++)used[i] = false;
			while (left.size()>0 || right.size()>0) {
				if (dir == 0) {
					if (left.front() <= time) {
						for (i = 0; i < n; i++) {
							if (left.size() > 0) {
								if (left.front() <= time) {
									for (j = 0; j < c; j++) {
										if (side[j] == left.front() && used[j]==false) {
											boat[j] = time+t;
											used[j] = true;
											break;
										}
									}
										
									left.pop();
									dir = 1;
								}
							}
						}
						time += t;
					}
					else {
						if (right.size() > 0) {
							if (right.front() <= time) {
								dir = 1;
								time += t;
							}
							else time++;
						}
					}
				}
				else {
					if (dir == 1) {
						if (right.size() > 0) {
							if (right.front() <= time) {
								for (i = 0; i < n; i++) {
									if (right.size() > 0) {
										if (right.front() <= time) {
											for (j = 0; j < c; j++) {
												if (side[j] == right.front() && used[j]==false) {
													boat[j] = time+t;
													used[j] = true;
													break;
												}
											}
											right.pop();
											dir = 0;
										}
									}
								}
								time += t;
							}
							else {
								if (left.size() > 0) {
									if (left.front() <= time) {
										dir = 0;
										time += t;
									}
									else time++;
								}
							}
						}
						else {
							if (left.front() <= time) {
								dir = 0;
								time += t;
							}
							else time++;
						}
					}

				}
			}
			for (j = 0; j < c; j++)cout << boat[j] << "\n";
	}
	return 0;
}
