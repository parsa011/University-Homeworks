#include "global.h"

#define DIFF ('a' - 'A')

int main()
{
  string f;
  cout << "Enter File Name : ";
  cin >> f;
  fstream file(f);
  if (!file) {
    cout << "File Not Found\n";
    return ERROR_FILE_NOT_FOUND;
  }
  int line_count = file_line_count(file);
  string lines[line_count];
  string line;
  int index = 0;
  while (getline(file, line)) {
    lines[index++] = line;
  }
  // close and open in truncate mode because we want to overrite the file
  file.close();
  file.open(f.c_str(), ios::out | ios::trunc);
  for (int i = 0; i < line_count; i++) {
    string current_line = lines[i];
    for (int j = 0; j < current_line.length(); j++) {
      char current_char = current_line.at(j);
      if (isalpha(current_char)) {
	if (current_char >= 'a')
	  file << (char)(current_char - DIFF);
	else
	  file << (char)(current_char + DIFF);
      } else
	file << current_char;
    }
    file << '\n';
  }
  file.close();
  return 0;
}
