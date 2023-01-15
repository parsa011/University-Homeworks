#include "global.h"

void get_chars(char buf[], int len)
{
	int a;
	for (int i = 0; i < len; i++) {
		cout << "Chars[" << i + 1 << "] : ";
		cin >> a;
		buf[i] = a;
	}
}

void create_possible_combinations(char buf[], int len, int index, string bag)
{
	if (bag.length() > len)
		return;
	cout << bag;
	string temp;
	for (int i = 0; i < len; i++) {
		if (i == index)
			continue;
		temp = bag;
		temp += buf[i];
		create_possible_combinations(buf, len, i, temp);
	}
}

int main()
{
	int len;
	cout << "Chars Count : ";
	cin >> len;

	char chars[len];
	get_chars(chars, len);

	for (int i = 0; i < len; i++) {
		create_possible_combinations(chars, len, i, char_to_str(chars[i]));
	}
	
	return 0;
}	
