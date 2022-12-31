#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

int main()
{
  string filename, line;
  cout << "Enter File name : ";
  cin >> filename;
  ifstream file (filename.c_str());
  while (getline(file, line)) {
    for (int i = line.length() - 1; i >= 0 ; i--) {
      cout << line[i];
    }
    cout << endl;
  }
  return 0;
}
