#include <iostream>
#include <string.h>

using namespace std;

int getint(string msg)
{
	cout << msg << endl;
	int n = 0;
	cin >> n;
	return n;
}

/*
 * assumed that answers to be corrent, like 8 and 2 and ...
 */
int log(int a , int b, int cur)
{
	if (cur == a)
		return 0;
	return log(a, b, cur * b) + 1;
}

int main()
{
	int a = 0, b = 0;
	a = getint("Enter a : ");
	b = getint("Enter b (base) : ");
	cout << "Log a(b) : " << log(a, b, 1) << endl;
	return 0;
}