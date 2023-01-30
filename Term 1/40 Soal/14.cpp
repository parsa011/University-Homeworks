#include "global.h"

const char *input_file = "class.bin";

int main()
{
  /*
    open file, if file dosn't exist
    exit with ERROR_FILE_NOT_FOUND (3) error code
  */
  fstream file(input_file);
  if (!file) {
    cout << "File Not Found!\n";
    return ERROR_FILE_NOT_FOUND;
  }
  
  int file_line = file_line_count(file);

  int scores[file_line];
  string names[file_line], ids[file_line];

  string line;
  int t = 0;
  while (getline(file, line)) {

    int index = 0;
    eat_until(line, ':', index);

    int score = lex_int(line, index);
    scores[t] = score;
    string name = lex_string(line, index);
    names[t] = name;
    string id = lex_string(line, index);
    ids[t] = id;

    t++;
  }

  int i, j;
  for (i = 0; i < file_line - 1; i++) {
    for (j = 0; j < file_line - i - 1; j++) {
      if (scores[j] < scores[j + 1]) {
		  int temp = scores[j];
		  scores[j] = scores[j + 1];
		  scores[j + 1] = temp;

		  names[j].swap(names[j + 1]);

		  ids[j].swap(ids[j + 1]);
      }
    }
  }
  
  cout << "Best Students : \n\n";
  for (i = 0; i < 3; i++) {
    if (i >= file_line)
      break;
    cout << names[i] << " (" << ids[i] << ") : " << scores[i] << endl;
  }

  return 0;
}
