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

struct date{
	int month;
	int day;
};
int main()
{
	map<string,int>month;
	month["Jan"]=1;
	month["Feb"]=2;
	month["Mar"]=3;
	month["Apr"]=4;
	month["May"]=5;
	month["Jun"]=6;
	map<int, string>rev;
	rev[1] = "Jan";
	rev[2] = "Feb";
	rev[3] = "Mar";
	rev[4] = "Apr";
	rev[5] = "May";
	rev[6] = "Jun";
	map<int, int>day;
	day[1] = 31;
	day[2] = day[1]+29;
	day[3] = day[2]+31;
	day[4] = day[3]+30;
	day[5] = day[4]+31;
	day[6] = day[5]+30;
	double initial;
	cin >> initial;
	string x, y;
	double z;
	vector<double>price(day[6]+5,initial);
	while (cin >> x >> y >> z){
		int start, end;
		stringstream xx(x);
		char op, comma;
		int d,year;
		string m;
		xx >> d >> op >> m;
		m.erase(3, m.length() - 3);
		if (month[m] == 1)start = d;
		else start = day[month[m]-1]+d;
		stringstream yy(y);
		yy >> d >> op >> m;
		m.erase(3, m.length() - 3);
		if (month[m] == 1)end = d;
		else end = day[month[m] - 1] + d;
		for (int i = start; i <= end; i++)price[i] = z;

		
		int cm = 1,pm=1;
		cout << "01-Jan-04   |";
		for (int i = 2; i <= day[6]; i++){
			if (i > day[cm])cm++;
			if (price[i] != price[i - 1]){
				cout << i-1 - day[pm-1] << "-" << rev[pm] << "-04   |" << price[i - 1] << "|\n";
				cout << i - day[cm-1] << "-" << rev[cm] << "-04   |";
			}
			if (i > day[pm])pm++;

		}
		cout << "30-Jun-04   |"<<price[day[6]]<<"\n";
	}

	return 0;
}
