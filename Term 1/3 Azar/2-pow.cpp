#include <iostream>

using namespace std;

int getint(string msg)
{
	cout << msg << endl;
	int n = 0;
	cin >> n;
	return n;
}

/*
 * recursive way , with every call we do sum * a, when we reached to 0, will return sum
 * assumed that b is bigger than 0 :)
 */
int pow(int a, int b, int sum)
{
	if (b <= 0)
		return sum;
	sum *= a;
	return pow(a, --b, sum);
}

int main()
{
	int a = 0, b = 0;
	a = getint("Enter Number : ");
	b = getint("Enter Pow : ");
	cout << "a ^ b : " << pow(a, b, 1);
	return 0;
}
