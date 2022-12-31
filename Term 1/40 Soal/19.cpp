#include "global.h"

int factorial(int n)
{
  if (n == 0 || n == 1)
    return 1;
  else
    return n * factorial(n - 1);
}

double calculate(int n, int n_base, double x, double x_pow)
{
  if (n_base == n)
    return 0;
  double res = pow(x, x_pow) / factorial(n_base);
  res += calculate(n, n_base + 2, x, x_pow + 2);
  return res;
}

int main()
{
  int n;
  double x;
  cout << "Enter n : ";
  do {
    cin >> n;
  } while (n % 2 == 0);
  cout << "Enter x : ";
  cin >> x;
  cout << x + calculate(n, 3, x, 3);
  return 0;
}
