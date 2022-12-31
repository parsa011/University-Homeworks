#include <iostream>

using namespace std;

void find_list(int n, int temp)
{
  if (temp <= 0)
    return;
  cout << "(" << temp << ", " << n - temp << ")\t";
  find_list(n, --temp);
}

int main()
{
  int n;
  cout << "Etner a Number : ";
  cin >> n;
  find_list(n, n - 1);
  return 0;
}
