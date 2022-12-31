#ifndef _GLOBAL_H
# define _GLOBAL_H

/*
  all are not needed in a single file , but we added :)))
*/
#include <iostream>
#include <string.h>
#include <fstream>
#include <math.h>
#include <Windows.h>

/*
  it can be a little dangerous , but not in our project i think :)))
*/
using namespace std;

static bool file_exist(char *file_path)
{
  fstream file(file_path);
  bool is_open = file.is_open();
  file.close();
  return is_open;
}

static long file_line_count(fstream &file)
{
  long count = 0;
  string line;
  while (getline(file, line))
    count++;
  // move cursor to the head of file
  file.clear();
  file.seekg(0);
  return count;
}

static void eat_until(string str, char ch, int &i)
{
  i = str.find(ch) + 1;
}

static void skip_space(string str, int &i)
{
  while (str[i]) {
    if (!isspace(str[i]))
      break;
    i++;
  }
}

static int lex_int(string str, int &i)
{
  skip_space(str, i);
  int sign = 1;
  if (str[i] == '-') {
    sign = -1;
    i++;
  }
  int res = 0;
  while (isdigit(str[i])) {
    res = res * 10 + (str[i++] - '0');
  }
  return res * sign;
}

static string lex_string(string str, int &i)
{
  skip_space(str, i);
  string s;
  while (str[i]) {
    if (isspace(str.at(i)))
	break;
    s += str[i++];
  }
  return s;
}

static int decimal_len(long n)
{
  n = abs(n);
  int len = 1;
  while (n / 10) {
    n /= 10;
    len++;
  }
  return len;
}

static int nthdigit(int n, int x)
{
  while (--x) {
    n /= 10;
  }
  return n % 10;
}


#endif
