#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

void show_info(string full_name, string st_number, string field, int term)
{
	string fn_field = "Full Name", stn_field = "Student Number", fd_field = "Field", tm_field = "Term";
	int padding = 4;
	int strings_max_length = max(fn_field.length(), max(stn_field.length(), max(tm_field.length(), fd_field.length()))) + padding;
	cout << "Full Name" << setw(strings_max_length - fn_field.length()) << ": " << full_name << endl;
	cout << "Student Number" << setw(strings_max_length - stn_field.length()) << ": " << st_number << endl;
	cout << "Field" << setw(strings_max_length - fd_field.length()) << ": " << field << endl;
	cout << "Term" << setw(strings_max_length - tm_field.length()) << ": " << full_name << endl;
}

int main()
{
	string full_name = "Parsa Mahmoudy";
	string st_number = "40120841054029";
	string field     = "CE";
	int    term      = 1;
	show_info(full_name, st_number, field, term); 
	return 0;
}