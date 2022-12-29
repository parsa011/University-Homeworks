#include <iostream>

using namespace std;

int get_pow(int n)
{
  int t = 1;
  while (1) {
    t *= 2;
    if (t > n) {
      t /= 2;
      return t;
    }
  }
  return 1;
}

void decimal_to_binary(int n)
{
  int pow = get_pow(n);
  while (pow > 0) {
    if (pow > n)
      cout << '0';
    else {
      cout << '1';
      n -= pow;
    }
    pow /= 2;
  }
  putchar('\n');
}

int main()
{
  int n;
  cout << "Enter a number\n";
  cin >> n;
  decimal_to_binary(n);
  return 0;
}
