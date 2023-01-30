#include "global.h"

void sort_lines(string lines[], int count)
{
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - i - 1; j++) {
			if (lines[i].compare(lines[j]) < 0) {
				string temp = lines[i];
				lines[i] = lines[j];
				lines[j] = temp;
			}
		}
	}
}

void show_lines(string lines[], int count)
{
	for (int i = 0; i < count; i++) {
		cout << lines[i] << endl;
	}
}

void write_lines(fstream &file, string lines[], int count)
{
	for (int i = 0 ; i < count; i++) {
		file << lines[i] << '\n';
	}
}

int main()
{
	string file_name;
	cout << "Enter File Name : ";
	cin >> file_name;

	fstream file(file_name.c_str());
	if (!file) {
		cout << "File Not Found\n";
		return 1;
	}

	int line_count = file_line_count(file);
	string lines[line_count];
	file_read_lines(file, lines, line_count);


	sort_lines(lines, line_count);

	file.close();
	file.open(file_name.c_str(), ios::out | ios::trunc);
	
	write_lines(file, lines, line_count);

	show_lines(lines, line_count);

	file.close();
	
	return 0;
}
