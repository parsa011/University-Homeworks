#include "global.h"

#define MAX 256

void get_collection(char db[], int &len)
{
	cout << "Enter Characters\n";
	char ch;
	for (int i = 0; i < len; i++) {
		cin >> ch;
		db[i] = ch;
	}
}

void create_possible_combinations(char db[], int len, int index, string str)
{
}

int main()
{
	char db[MAX];
	int len;
	do {
		cout << "How Many Number You want (less than " << MAX << ") ? ";
		cin >> len;
	} while (len > MAX);
	get_collection(db, len);
	int sub_collections = (int)pow(2, len) - 1;
	for (int i = 0; i < len; i++) {
		create_possible_combinations(db, len, db[i], i);
	}
	return 0;
}
