#include <iostream>

using namespace std;

int main()
{
  int n = 0;
  cout << "Enter a Number\n";
  cin >> n;
  int temp = 0;
  for (int i = 2; i < n; i++) {
    if (n % i == 0)
      temp++;
  }
  if (temp != 0)
    cout << "Number is Not Prime\n";
  else
    cout << "Numer is Prime\n";
  return 0;
}
