#include "global.h"
#include <limits.h>

int main()
{
  const char *output_file = "ASCII.DOT";
  fstream file(output_file, ios::out);
  int count = 0;
  for (int i = 1; i <= 256; i++) {
    file << (char)i << '\t';
    count++;
    if (count == 12) {
      file << '\n';
      count = 0;
    }
  }
  file.close();
  return 0;
}
