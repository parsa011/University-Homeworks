#include "global.h"

int main()
{
  string f1, f2;
  cout << "Enter Files Name : \n";
  cin >> f1 >> f2;
  fstream file1(f1.c_str());
  fstream file2(f2.c_str());
  if (!file1 || !file2) {
    cout << "Invalid Files\n";
    return ERROR_FILE_NOT_FOUND;
  }
  file1.seekg(0, ios_base::end);
  int length = file2.tellg();
  file2.seekg(length, ios_base::beg);
  string line;
  while (getline(file2, line))
    file1 << line.c_str() << '\n';
  file1.close();
  file2.close();
  return 0;
}
