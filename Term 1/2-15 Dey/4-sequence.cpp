#include <iostream>

using namespace std;

#define COUNT 20

void write_sequence(int first, int step)
{
	for (int i = 0; i < COUNT; i++) {
		cout << first + step * i << '\t';
	}
	cout << endl;
}

int main()
{
	int first, step;
	cout << "Enter First Sequence : ";
	cin >> first;
	cout << "Enter Step : ";
	cin >> step;
	write_sequence(first, step);
	return 0;
}
