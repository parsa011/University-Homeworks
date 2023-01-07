#include <iostream>

using namespace std;

#define COUNT 20

int main()
{
	int first;
	cout << "Enter First Sequence : ";
	cin >> first;
	int step;
	cout << "Enter Step : ";
	cin >> step;
	for (int i = 0; i < COUNT; i++) {
		cout << first + step * i << '\t';
	}
	cout << endl;
	return 0;
}
