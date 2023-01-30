#include "global.h"

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

/*
  https://www.tutorialspoint.com/find-x-and-y-satisfying-ax-plus-by-n-in-cplusplus
*/
void solve(int a, int b, int c)
{
	if (c % gcd(a, b) != 0) {
		cout << "There Is No Any Answer\n";
	} else {
		for (int i = 0; i * a <= c; i++) {
			if ((c - (i * a)) % b == 0) {
				cout << i << " and "<< (c - (i * a)) / b;
			}
		}
	}
}

void get_no_0(int &n, char *msg)
{
	cout << msg;
	do {
		cin >> n;
	} while (n == 0);
}

int main()
{
	int a, b, c;
	get_no_0(a, (char *)"Enter a (not 0) : ");
	get_no_0(b, (char *)"Enter b (not 0) : ");
	cout << "Enter c : ";
	cin >> c;
	solve(a, b, c);
	return 0;
}
