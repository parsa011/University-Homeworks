#include "global.h"

/*
  also we can return that number as a double
  but that's enough :))
*/
void decimal_to_octal(long double n)
{
  string res("");
  long double temp = n * pow(8, 8);
  long double rem = 0;
  while (temp != 0) {
    rem = floor(fmod(temp, 8));
    temp = floor(temp / 8);
    res += to_string((int)rem);
  }
  int decimal_length = res.length() - 8;
  for (int i = res.length() - 1; i >= 0; i--) {
    decimal_length--;
    cout << res.at(i);
    if (decimal_length == 0)
      cout << ".";
  }
}
const char *hex_table[] = {
  "0",	"1",  "2",  "3",
  "4",  "5",  "6",  "7",
  "8",  "9",  "A",  "B",
  "C",  "D",  "E",  "F"
};
void decimal_to_hexa(long double n)
{
  string res("");
  long double temp = n * pow(16, 8);
  long double rem = 0;
  while (temp != 0) {
    rem = floor(fmod(temp, 16));
    temp = floor(temp / 16);
    res += hex_table[(int)rem];
  }
  int decimal_length = res.length() - 8;
  for (int i = res.length() - 1; i >= 0; i--) {
    decimal_length--;
    cout << res.at(i);
    if (decimal_length == 0)
      cout << ".";
  }
}

int main()
{
  long double n;
  cout << "Enter Your Number : ";
  cin >> n;
  cout << "in Octal : ";
  decimal_to_octal(n);
  cout << "\nin Hexadecimal : ";
  decimal_to_hexa(n);
  return 0;
}
