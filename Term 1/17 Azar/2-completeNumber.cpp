#include <iostream>

using namespace std;

int main()
{
  int n = 0, sum = 0;
  cout << "Enter A Number : \n";
  cin >> n;
  for (int i = 1; i <= n / 2; i++) {
    if (n % i == 0)
      sum += i;
  }
  if (sum == n)
    cout << "Number is Complete\n";
  else
    cout << "Numer is not Complete\n";
  return 0;
}
