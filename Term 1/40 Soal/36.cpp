#include "global.h"

int main()
{
	string str;
	cout << "Enter Your String To Search : ";
	cin >> str;

	fstream file("Sample.BIN");
	string line;
	int line_no = 1;
	while (getline(file, line)) {
		if (line.find(str) != string::npos) {
			cout << line_no << " : " << line << endl;
		}
		line_no++;
	}
	return 0;
}
