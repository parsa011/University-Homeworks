#include <iostream>

using namespace std;

const char *files_name[] = {"Rec1.bin", "Rec2.bin", "Rec3.bin"};
const char *out_put = "eat.bin";

void open_files(ifstream recs[])
{
  for (int i = 0; i < 3; i++) {
    ostringstream filename;
    filename << files_name[i];
    recs[i].open(filename.str());
  }
}

int main()
{
  ifstream recs[3];
  open_files(recs);
  return 0;
}
