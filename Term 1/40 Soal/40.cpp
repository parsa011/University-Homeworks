#include "global.h"

void print_numbers(string str)
{
	if (str.length() == 5) {
		cout << str << endl;
		return;
	}
	string temp;
	for (int i = 1; i < 10; i++) {
		if (str.find(i + '0') < str.length())
			continue;
		temp = str;
		temp += to_string(i);
		print_numbers(temp);
	}
}

int main()
{
	for (int i = 1; i < 10; i++)
		print_numbers(string(to_string(i)));
	return 0;
}
