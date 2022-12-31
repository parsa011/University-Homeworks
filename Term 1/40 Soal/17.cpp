#include "global.h"

const char *numbers[] = {
  "zero",
  "one",
  "two",
  "three",
  "four",
  "five",
  "six",
  "seven",
  "eight",
  "nine",
  "ten",
  "eleven",
  "twelve",
  "thirteen",
  "fourteen",
  "fifteen",
  "sixteen",
  "seventeen",
  "eighteen",
  "nineteen" 
};

const char *tens[] = {
  "twenty",
  "thirty",
  "fourty",
  "fifty",
  "sixty",
  "seventy",
  "eighty",
  "ninety"
};

void write_tens(int n)
{
  int index = n / 10;
  if (n > 19) {
    cout << tens[index - 2];
    if (n % 10 != 0)
      cout << "-" << numbers[n % 10];
  } else {
      cout << numbers[n];
   }
}

void write_hundreds(int n)
{
  cout << numbers[n] << " hundreds ";
}

int nthdigit(int n, int x)
{
    while (--x) {
        n /= 10;
    }
    return n % 10;
}

void convert(int n)
{
  int len = decimal_len(n);
  if (len > 5) {
    cout << "Too Many Digits\n";
    return;
  }
  int l = 0;
  for (int i = len; i > 0; i--) {
    switch (i) {
    case 5 :
    case 4 :
      l = n / 1000;
      write_tens(l);
      cout << " thousands ";
      if (i == 5)
	i--;
      break;
    case 3 :
      l = nthdigit(n, 3);
      if (l != 0)
      write_hundreds(nthdigit(n, 3));
      break;
    case 2 :
    case 1 :
      if (i == 1) {
	l = nthdigit(n, 1);
	if (l != 0)
	  write_tens(nthdigit(n, 1));
      }
      if (i == 2) {
	l = nthdigit(n, 2) * 1- + nthdigit(n, 1);
	if (l != 0)
	  write_tens(nthdigit(n, 2) * 10 + nthdigit(n, 1));
	i--;
      }
      break;
    }
  }
}

int main()
{
  int n;
  cout << "Enter Your Number : ";
  cin >> n;
  convert(n);
  return 0;
}
