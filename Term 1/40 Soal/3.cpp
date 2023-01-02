#include "global.h"

int main()
{
  string line;
  cout << "Enter Your Line : ";
  getline (cin, line);
  for (int i = 0; i < line.length();) {
    while (isspace(line.at(i)))
      i++;
    int first = 0;
    while (i < line.length() && !isspace(line.at(i))) {
      char ch = line.at(i);
      first++;
      if (isalpha(ch) && (ch >= 'a' && first == 1)) {
	cout << (char)(ch - ('a' - 'A'));
	first = 1;
      } else
	cout << ch;
      i++;
    }
    cout << endl;
  }
  return 0;
}
