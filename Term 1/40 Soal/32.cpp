#include "global.h"

#define FILENAME "ABC.BIN"

typedef struct {
	string name;
	int count;
} record;

int read_records(fstream &file, record records[])
{
	string line, name;
	int i, count;
	int index = 0;
	while (getline(file, line)) {
		i = 0;
		skip_space(line, i);
		records[index].name = lex_string(line, i);
		skip_space(line, i);
		records[index++ ].count = lex_int(line, i);
	}
	return index;
}

void show_records(record records[], int len)
{
	int i, j, max_count = 0, max_len = 0;
	for (i = 0; i < len; i++) {
		max_count = max(records[i].count, max_count);
		max_len = max((int)records[i].name.length(), max_len);
	}
	int temp_count = max_count;
	for (j = 0; j < max_count; j++, temp_count--) {
		for (i = 0; i < len; i++) {
			if (records[i].count >= temp_count)
				cout << "*";
			else
				cout << " ";
			cout << '\t';
		}
		cout << endl;
	}
	int space = 1;
	for (i = 0; i < max_len; i++, space++) {
		for (j = 0; j < len; j++) {
			cout << setw(space);
			if (i < records[j].name.length())
				cout << records[j].name[i];
			else
				cout << " ";
			cout << '\t';
		}
		cout << endl;
	}
}

int main()
{
	fstream file(FILENAME);
	int line_count = file_line_count(file);
	record records[line_count];
	int count = read_records(file, records);
	show_records(records, count);
	return 0;
}
