#include <iostream>
#include <math.h>
#include <limits.h>

using namespace std;

#define ARR_LENGTH 50

int main()
{
  int sum = 0, avg = 0;
  int array[ARR_LENGTH];
  int n = 0;
  cout << "Enter " << ARR_LENGTH << " Number\n";
  for (int i = 0; i < ARR_LENGTH; i++) {
    cout << i + 1 << " : ";
    cin >> n;
    array[i] = n;
    sum += n;
  }
  avg = sum / ARR_LENGTH;
  cout << "Average : " << avg << endl;

  // calculating nearest number to avg
  int index = -1, remaining = INT_MAX;

  for (int i = 0; i < ARR_LENGTH; i++) {
    int x = abs(avg - array[i]);
    if (x < remaining) {
      index = i;
      remaining = x;
    }
  }
  cout << "Nearest Number to Avg is : " << array[index];
  
  return 0;
}

