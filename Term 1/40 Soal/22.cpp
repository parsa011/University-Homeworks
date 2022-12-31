#include "global.h"

int main()
{
  string word, f;
  cout << "Enter File Name : ";
  cin >> f;
  cout << "Enter Word : ";
  cin >> word;
  fstream file(f.c_str());
  if (!file) {
    cout << "File Not Found\n";
    return ERROR_FILE_NOT_FOUND;
  }
  string line;
  int line_no = 1, count = 0;
  while (getline(file, line)) {
    if (strstr(line.c_str(), word.c_str())) {
      cout << line_no << " : " << line << endl;
      count++;
    }
    line_no++;
  }
  if (count == 0) {
    cout << "Not Found\n";
  } else
    cout << count << " Found\n";
  file.close();
  return 0;
}
