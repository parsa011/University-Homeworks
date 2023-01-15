#include "global.h"


void get_chars(char buf[], int len)
{
	char a;
	for (int i = 0; i < len; i++) {
		cout << "Chars[" << i + 1 << "] : ";
		cin >> a;
		buf[i] = a;
	}
}

void create_possible_combinations(char buf[], int len, int index, int max, string bag)
{
	if (bag.length() > max)
		return;
	if (bag.length() == max)
		cout << bag << '\t';
	string temp;
	for (int i  = index + 1; i < len; i++) {
		temp = bag;
		temp += buf[i];
		create_possible_combinations(buf, len, i, max, temp);
	}
}

int main()
{
	int len;
	cout << "Chars Count : ";
	cin >> len;

	int max;
	do {
		cout << "Enter Max Len for collections : ";
		cin >> max;
	} while (max > len);

	char chars[len];
	get_chars(chars, len);

	for (int i = 0; i < len; i++) {
		create_possible_combinations(chars, len, i, max, char_to_str(chars[i]));
	}
	
	return 0;
}	
