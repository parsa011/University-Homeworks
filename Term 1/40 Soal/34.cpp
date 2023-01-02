#include "global.h"

#define COUNT 200

int main()
{
  long double S = 0;
  int x;
  cout << "Enter a Number : ";
  cin >> x;
  long double last_x_sentence = x;
  S = 1 / x;
  long double sign = -1;
  for (int i = 1; i < COUNT; i++) {
    last_x_sentence += (i + 1) * (pow(x, i + 1));
    S += sign *(1 / x + last_x_sentence);
    sign *= -1;
  }
  cout << "Result is : " << S << endl;
  return 0;
}
