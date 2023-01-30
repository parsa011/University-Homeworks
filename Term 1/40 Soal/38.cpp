#include "global.h"

#define FILEN "IDX.BIN"

int main()
{
	fstream file(FILEN);
	
	string str;
	cout << "Enter Last Name To Delete : ";
	cin >> str;

	int line_count = file_line_count(file);
	string lines[line_count];
	file_read_lines(file, lines, line_count);

	file.close();
	file.open(FILEN, ios::out | ios::trunc);

	int index;
	for (int i = 0; i < line_count; i++) {
		index = 0;
		lex_string(lines[i], index);
		if (strncmp(lines[i].c_str() + index + 1, str.c_str(), str.length()) != 0)
			file << lines[i] << '\n';
	}

	file.close();
	return 0;
}
