// String Practice.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>

using namespace std;
int x,i,a;
string y;
int main()
{
	//ch = 'A';
	//while (ch <= 'Z') {
	//	cout << ch;
	//	ch++;
	//}
	//print Z through Z

	//cin >> ch;
	//x = ch -64;
	//cout << x;
	//return 0;
	//print the number the character represents
	
	//cin >> y;
	//x = y.length();
	//for (i = 0; i < x; i++)
	//{
	//	char ch = y[i];
	//	cout << ch<<"\n";
	//}
	//print every character line by line
	
	//y = "ABC";
	//y.insert(1, "+");
	//y.insert(3, "+");
	//cout << y<<"\n";
	//y.erase(2, 2);
	//cout << y<<"\n";
	//y.replace(1,1, "-");
	//cout << y;
	//insert, erase, and replace exercise
	int b;
	cin >> y;
	x = y.length();
	a = y.find("a");
	while (a != std::string::npos)
	{
		y = y.replace(a, 1, "z");
		a = y.find("a");
	}
	b = y.find("A");
	while (b != std::string::npos)
	{
		
		y = y.replace(b, 1, "Z");
		b = y.find("A");
	}
		cout << y << "\n";
		std::string a = y.substr(1);
		cout << a << "\n";

	return 0;
}

