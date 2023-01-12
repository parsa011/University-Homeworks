#include <iostream>
#include <math.h>

using namespace std;

int digit_count(int n)
{
	return floor(log10(abs(n))) + 1;
}

int main()
{
	int a;
	cout << "Enter A Number : ";
	cin >> a;
	cout << a << " has '" << digit_count(a) << "' digit\n";
	return 0;
}
