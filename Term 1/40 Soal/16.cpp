#include "global.h"

int main()
{
  long waterloo_capacity = 50000;
  int waterloo_increase_rate = 10;
  long toronto_capacity = 22000000;
  int toronto_increase_rate = 2;

  int year = 1975;
  while (waterloo_capacity <= toronto_capacity) {
    waterloo_capacity += waterloo_capacity / 100 * waterloo_increase_rate;
    toronto_capacity += toronto_capacity / 100 * toronto_increase_rate;
    year++;
  }
  cout << waterloo_capacity << '\t' << toronto_capacity << endl;
  cout << "In : " << year << endl;
  return 0;
}
