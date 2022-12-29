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
 * also we can use math way like log, but easier way
 */
int digit_count(int a)
{
	return to_string(a).length();
}

int main()
{
	int a = getint("Enter a number : ");
	// using loop just for skiping zeros, not used for algorithm
	while (a == 0)
		a = getint("Enter a number : ");
	cout << "number '" << a << "' has " << digit_count(a) << " digit" << endl;
	return 0;
}