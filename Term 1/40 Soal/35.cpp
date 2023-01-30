#include "global.h"

#define OUTPUT "IDX.BIN"
#define INPUT "Sample.BIN"

void sort(string lines[], int count)
{
	int i, j;
	for (i = 0; i < count; i++) {
		for (j = 0; j < count - i - 1; j++) {
			if (lines[i].compare(lines[j]) < 0) {
				string temp = lines[i];
				lines[i] = lines[j];
				lines[j] = temp;
			}
		}
	}
}

void show_lines(string line[], int count)
{
	for (int i = 0; i < count; i++)
		cout << line[i] << endl;
}

void write_lines(fstream &file, string lines[], int count)
{
	for (int i = 0 ; i < count; i++) {
		file << lines[i] << '\n';
	}
}

int main()
{
	fstream input(INPUT), out_put;
	if (!input) {
		cout << "File Not Found\n";
		return 1;
	}
	int line_count = file_line_count(input);
	string lines[line_count];
	file_read_lines(input, lines, line_count);
	show_lines(lines, line_count);
	sort(lines, line_count);

	out_put.open(OUTPUT, ios::out | ios::trunc);
	write_lines(out_put, lines, line_count);
	
	show_lines(lines, line_count);
	
	out_put.close();
	input.close();
	return 0;
}
