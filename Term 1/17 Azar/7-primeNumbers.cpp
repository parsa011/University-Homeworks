#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  int n, m;
  int max_n, min_n;
  cout << "Enter Numbers\n";
  cin >> n >> m;
  max_n = max(n, m);
  min_n = min(n, m);
  int prime_numbers[max_n];
  int i;
  for (i = 0; i < min_n; i++)
    prime_numbers[i] = 0;
  for (i = min_n; i < max_n; i++)
    prime_numbers[i] = 1;
  for (i = 2; i <= max_n / 2; i++) {
    for (int j = 2; j <= max_n / i; j++) {
      cout << i << '\t' << j << endl;
      prime_numbers[i * j] = 0;
    }
  }
  for (i = min_n; i <= max_n; i++)
    if (prime_numbers[i] == 1)
      cout << i << '\t';
  cout << endl;
  return 0;
}

