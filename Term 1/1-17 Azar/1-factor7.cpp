#include <iostream>

using namespace std;

int main()
{
  int max_num = 0, n = 0;
  cout << "Enter a Number ? \n";
  cin >> max_num;
  for (int i = max_num - 1; i >= 7; i--) {
    // finding first factor of 7
    if (i % 7 == 0) {
      for (;i >= 7; i -= 7)
	cout << i << '\t';
    }
  }
  cout << endl;
  return 0;
}
