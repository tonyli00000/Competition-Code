/*
ID: tonyli21
PROG: fence8
LANG: C++11
*/

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


const int MAX_RAIL = 1024;

int N, R;
int rail[MAX_RAIL];
int board[50];
int boardsum;
int railsum[MAX_RAIL];
int cut_rail_from[MAX_RAIL];
int max_waste, cur_waste;

bool SmallFirst(int a, int b){ return a < b; }
bool BigFirst(int a, int b){ return a > b; }

void init(){
	freopen("fence8.in", "r", stdin);
	freopen("fence8.out", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> board[i];
		boardsum += board[i];
	}
	cin >> R;
	for (int i = 0; i < R; i++){
		cin >> rail[i];
	}
	sort(rail, rail + R, SmallFirst);
	sort(board, board + N, BigFirst);  
	while (rail[R - 1] > board[0] && R > 0)    R--;
	while (N > 0 && board[N - 1] < rail[0])    N--;
	if (R == 0 || N == 0){   //The case there is no solution;  
		cout << 0 << endl;
		exit(0);//Note to exit, not return;  
	}
	railsum[0] = rail[0];
	for (int i = 1; i < R; i++){
		railsum[i] = railsum[i - 1] + rail[i];
	}
}

bool DFS_Check(int index){
	if (cur_waste > max_waste) return 0;
	if (index < 0) return 1;
	int start = 0;
	if (rail[index] == rail[index + 1]) //Note the case index == 1022; so we allocate 1024 for rail;   
		start = cut_rail_from[index + 1];
	for (int i = start; i < N; i++){
		if (board[i] >= rail[index]){
			board[i] -= rail[index];
			cut_rail_from[index] = i;
			if (board[i] < rail[0]) cur_waste += board[i];
			int remain = DFS_Check(index - 1);
			//restore;  
			if (board[i] < rail[0]) cur_waste -= board[i];
			cut_rail_from[index] = -1;
			board[i] += rail[index];
			// We only need one of the solution to put remain rails;  
			// Once we cind it, return true right away;  
			if (remain) return 1;
		}
	}
	return 0;
}

void BinarySearch(){
	for (int i = 0; i < R; i++) cut_rail_from[i] = -1;
	int low = 0, hight = R - 1;
	for (; hight >= 0 && boardsum < railsum[hight]; hight--);
	while (low < hight){
		//Note here we plus 1 because when low +1 == hight, we want to check mid == hight;   
		int mid = (low + hight + 1) / 2;
		max_waste = boardsum - railsum[mid];
		if (DFS_Check(mid)) low = mid;
		else hight = mid - 1;
	}
	cout << low + 1 << endl;
}

int main(){
	init();
	BinarySearch();
	return 0;
}