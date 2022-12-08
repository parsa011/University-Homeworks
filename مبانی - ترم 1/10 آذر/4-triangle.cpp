#include <iostream>

using namespace std;

int main()
{
  int a = 0, b = 0, c = 0;
  cout << "Enter a , b and c In Order : (Press Enter After Each Number)\n";
  cin >> a >> b >> c;
  if (
      (a + b > c)
      &&
      (a + c > b)
      &&
      (b + c > a)
      ) {
    cout << "Possible\n";
  } else {
    cout << "Impossible\n";
  }
  return 0;
}
