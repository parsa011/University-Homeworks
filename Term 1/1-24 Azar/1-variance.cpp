#include <iostream>
#include <math.h>

using namespace std;

int main()
{
  int count = 6;
  float numbers[count] = {};
  float avg = 0, variance = 0, n;
  for (int i = 0; i < count; i++) {
    cout << "number[" << i + 1 << "] : ";
    cin >> n;
    avg += n;
    numbers[i] = n;
  }
  avg /= count;
  for (int i = 0; i < count; i++) {
    variance += pow((numbers[i] - avg), 2);
  }
  variance /= count;
  cout << "Variance : " << variance << "\tStandard Deviation : " << sqrt(variance) << endl;
  return 0;
}
