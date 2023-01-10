#include "global.h"

using namespace std;

const char *files_name[] = {"Rec1.bin", "Rec2.bin", "Rec3.bin"};
const char *out_put = "eat.bin";

void open_files(fstream recs[])
{
	for (int i = 0; i < 3; i++) {
		recs[i].open(files_name[i]);
	}
}

void close_files(fstream files[])
{
	for (int i = 0; i < 3; i++) {
		files[i].close();
	}
}

int main()
{
	fstream recs[3];
	open_files(recs);
	fstream output(out_put, ios::out | ios::trunc);
	string line;
	for (int i = 0; i < 3; i++) {
		while (getline(recs[i], line)) {
			output << line << '\n';
		}
	}
	close_files(recs);
	return 0;
}
