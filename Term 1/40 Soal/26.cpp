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

void create_possible_combinations(string db[], int index, string bag, int max_len)
{
	if (bag.length() > max_len)
		return;
	bag += "0";
	db[index++] = bag;
	create_possible_combinations(db, index, bag, max_len);
	string temp(bag);
	bag += "1";
	db[index++] = temp;
	create_possible_combinations(db, index, temp, max_len);
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
	string combinations[sub_collections];
	create_possible_combinations(combinations, 0, "", len);
	for (int i = 0; i < sub_collections; i++) {
		cout << combinations[i] << endl;
	}
	return 0;
}
