#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

int getint(string msg)
{
	cout << msg << endl;
	int n = 0;
	cin >> n;
	return n;
}

int main()
{
	int angle = getint("Enter Angle by Degree : ");
	cout << "SIN : " << sin(angle) << endl;
	cout << "COS : " << cos(angle) << endl;
	cout << "TAN : " << tan(angle) << endl;
	cout << "COT : " << cos(angle) / sin(angle) << endl;
	return 0;
}